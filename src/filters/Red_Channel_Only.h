#ifndef RED_CHANNEL_ONLY_H
#define RED_CHANNEL_ONLY_H

#include <iostream>
#include "Filter.h"
using namespace std;

class Red_Channel_Only : public Filter {
private:
    bool enabled;

public:
    Red_Channel_Only();
    ~Red_Channel_Only();
    
    bool isEnabled();
    void setEnabled(bool e);
    void applyFilter() override;
};

#endif
