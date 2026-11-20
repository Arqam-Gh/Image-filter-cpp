#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
using namespace std;

class Interface {
private:
    string interfaceID;
    string theme;

public:
    Interface();
    ~Interface();
    
    string getInterfaceID();
    void setInterfaceID(string id);
    string getTheme();
    void setTheme(string t);
    void renderUI();
};

#endif
