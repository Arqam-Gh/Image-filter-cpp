#ifndef GREEN_CHANNEL_ONLY_H
#define GREEN_CHANNEL_ONLY_H

#include <iostream>
#include "Filter.h"
using namespace std;

class Green_Channel_Only : public Filter {
private:
    bool enabled;

public:
    Green_Channel_Only();
    ~Green_Channel_Only();
    
    bool isEnabled();
    void setEnabled(bool e);
    void applyFilter() override;
};

#endif
