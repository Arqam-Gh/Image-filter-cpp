#include "File.h"
#include <iostream>
using namespace std;

File::File() : width(""), height(""), path(""), format("") {
}

File::~File() {
}

string File::getWidth() {
    return width;
}

void File::setWidth(string w) {
    width = w;
}

string File::getHeight() {
    return height;
}

void File::setHeight(string h) {
    height = h;
}

string File::getPath() {
    return path;
}

void File::setPath(string p) {
    path = p;
}

string File::getFormat() {
    return format;
}

void File::setFormat(string f) {
    format = f;
}
