#ifndef BLUE_CHANNEL_ONLY_H
#define BLUE_CHANNEL_ONLY_H

#include <iostream>
#include "Filter.h"
using namespace std;

class Blue_Channel_Only : public Filter {
private:
    bool enabled;

public:
    Blue_Channel_Only();
    ~Blue_Channel_Only();
    
    bool isEnabled();
    void setEnabled(bool e);
    void applyFilter() override;
};

#endif
