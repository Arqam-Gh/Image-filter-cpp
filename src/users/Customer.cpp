#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer() : username(""), email("") {
}

Customer::Customer(string uname, string mail) : username(uname), email(mail) {
}

Customer::~Customer() {
}

string Customer::getUsername() {
    return username;
}

void Customer::setUsername(string uname) {
    username = uname;
}

string Customer::getEmail() {
    return email;
}

void Customer::setEmail(string mail) {
    email = mail;
}

void Customer::viewProfile() {
}
