#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "User.h"
using namespace std;

class Admin : public User {
private:
    string adminID;
    string role;

public:
    Admin();
    Admin(string id, string r);
    ~Admin();
    
    string getAdminID();
    void setAdminID(string id);
    string getRole();
    void setRole(string r);
    void manageUsers();
    void manageContent();
};

#endif
