#include "File_Vertical.h"
#include <iostream>
using namespace std;

File_Vertical::File_Vertical() : File(), orientation("vertical") {
}

File_Vertical::~File_Vertical() {
}

string File_Vertical::getOrientation() {
    return orientation;
}

void File_Vertical::setOrientation(string o) {
    orientation = o;
}
