#include "File_Horizontal.h"
#include <iostream>
using namespace std;

File_Horizontal::File_Horizontal() : File(), orientation("horizontal") {
}

File_Horizontal::~File_Horizontal() {
}

string File_Horizontal::getOrientation() {
    return orientation;
}

void File_Horizontal::setOrientation(string o) {
    orientation = o;
}
