#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>
#include <vector>
#include <system_error>
#include <exception>
using namespace std;

// Include all header files
#include "Pixel.h"
#include "Image.h"
#include "File.h"
#include "File_Vertical.h"
#include "File_Horizontal.h"
#include "Blue_Blur.h"
#include "Blue_Channel_Only.h"
#include "Green_Channel_Only.h"
#include "Red_Channel_Only.h"
#include "Grayscale.h"
#include "Invert.h"
#include "Brightness_Adjust.h"
#include "Flip_Horizontal.h"
#include "Flip_Vertical.h"
#include "Image_file_manager.h"
#include "Catalog.h"
#include "Session.h"
#include "FilterSession.h"
#include "Customer.h"
#include "Admin.h"
#include "Schedule.h"
#include "Sampler.h"
#include "Interface.h"

void runFilter(IO& io, Image* original, Filter& filter, string name, string filterName) {
    Image copy(*original);
    filter.setImage(&copy);
    filter.applyFilter();
    string path = "examples/output/" + name + "/" + name + "_" + filterName + ".png";
    if (io.imagewrite((char*)path.c_str(), &copy) == 0) {
        cout << "Failed to write " << path << endl;
    } else {
        cout << "Saved " << path << endl;
    }
}

int main() {
    // Create instances of classes
    
    // Pixel class
    Pixel pixel1(255, 0, 0);
    Pixel pixel2;
    
    // Image class
    Image image1(800, 600);
    Image image2;
    
    // File classes
    File file1;
    File_Vertical fileVert;
    File_Horizontal fileHoriz;
    
    // Filter classes
    Blue_Blur blueBlur;
    Blue_Channel_Only blueChannel;
    Green_Channel_Only greenChannel;
    Red_Channel_Only redChannel;
    Grayscale grayscale;
    Invert invert;
    Brightness_Adjust brightness;
    
    // Catalog class
    Catalog catalog;
    
    // Session classes
    Session session1;
    FilterSession filterSession;
    
    // Customer and Admin
    Customer customer("user123", "user@example.com");
    Admin admin("admin001", "superuser");
    
    // Schedule and Sampler
    Schedule schedule;
    Sampler sampler;
    
    // Interface
    Interface interface;
    
    cout << "All objects created successfully!" << endl;
    
    error_code ec;
    if (!filesystem::is_directory("examples/input", ec)) {
        cout << "examples/input not found. Run the program from the project root." << endl;
        return 1;
    }

    try {
        IO io;
        vector<string> files;
        for (auto& entry : filesystem::directory_iterator("examples/input")) {
            files.push_back(entry.path().filename().string());
        }
        sort(files.begin(), files.end());

        for (size_t n = 0; n < files.size(); n++) {
            string name = files[n].substr(0, files[n].find_last_of('.'));
            string inPath = "examples/input/" + files[n];
            Image* original = io.imageread((char*)inPath.c_str());
            if (original == nullptr) continue;
            filesystem::create_directories("examples/output/" + name);

            Red_Channel_Only red;
            Green_Channel_Only green;
            Blue_Channel_Only blue;
            Grayscale gray;
            Invert inv;
            Brightness_Adjust plus50;
            Brightness_Adjust minus50;
            Blue_Blur blur;
            plus50.setLevel(50);
            minus50.setLevel(-50);
            blur.setIntensity(5);

            runFilter(io, original, red, name, "red_only");
            runFilter(io, original, green, name, "green_only");
            runFilter(io, original, blue, name, "blue_only");
            runFilter(io, original, gray, name, "grayscale");
            runFilter(io, original, inv, name, "invert");
            runFilter(io, original, plus50, name, "brightness_plus50");
            runFilter(io, original, minus50, name, "brightness_minus50");
            runFilter(io, original, blur, name, "blue_blur");

            if (name == "flip_parrot" || name == "odd_size_staircase") {
                Flip_Horizontal flipH;
                Flip_Vertical flipV;
                runFilter(io, original, flipH, name, "flip_horizontal");
                runFilter(io, original, flipV, name, "flip_vertical");
            }
            delete original;
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
