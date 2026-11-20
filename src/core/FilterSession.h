#ifndef FILTERSESSION_H
#define FILTERSESSION_H

#include <iostream>
#include "Session.h"
#include "Image.h"
using namespace std;

class FilterSession : public Session {
private:
    Image* appliedImage;
    string filterType;

public:
    FilterSession();
    ~FilterSession();
    
    Image* getAppliedImage();
    void setAppliedImage(Image* img);
    string getFilterType();
    void setFilterType(string type);
    void applySessionFilter();
};

#endif
