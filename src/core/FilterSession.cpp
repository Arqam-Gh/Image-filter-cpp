#include "FilterSession.h"
#include <iostream>
using namespace std;

FilterSession::FilterSession() : Session(), appliedImage(nullptr), filterType("") {
}

FilterSession::~FilterSession() {
}

Image* FilterSession::getAppliedImage() {
    return appliedImage;
}

void FilterSession::setAppliedImage(Image* img) {
    appliedImage = img;
}

string FilterSession::getFilterType() {
    return filterType;
}

void FilterSession::setFilterType(string type) {
    filterType = type;
}

void FilterSession::applySessionFilter() {
}
