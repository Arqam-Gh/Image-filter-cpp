#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "User.h"
using namespace std;

class Customer : public User {
private:
    string username;
    string email;

public:
    Customer();
    Customer(string uname, string mail);
    ~Customer();
    
    string getUsername();
    void setUsername(string uname);
    string getEmail();
    void setEmail(string mail);
    void viewProfile();
};

#endif
