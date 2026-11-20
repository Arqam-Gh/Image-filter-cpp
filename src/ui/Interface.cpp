#include "Interface.h"
#include <iostream>
using namespace std;

Interface::Interface() : interfaceID(""), theme("") {
}

Interface::~Interface() {
}

string Interface::getInterfaceID() {
    return interfaceID;
}

void Interface::setInterfaceID(string id) {
    interfaceID = id;
}

string Interface::getTheme() {
    return theme;
}

void Interface::setTheme(string t) {
    theme = t;
}

void Interface::renderUI() {
}
