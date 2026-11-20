#ifndef FILTER_H
#define FILTER_H

class Image;

// Base class for every filter. Each filter must implement applyFilter().
class Filter {
protected:
    Image* image;

public:
    Filter() : image(nullptr) {}
    virtual ~Filter() {}
    void setImage(Image* img) { image = img; }
    virtual void applyFilter() = 0;
};

#endif
