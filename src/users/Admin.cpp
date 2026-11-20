#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin() : adminID(""), role("") {
}

Admin::Admin(string id, string r) : adminID(id), role(r) {
}

Admin::~Admin() {
}

string Admin::getAdminID() {
    return adminID;
}

void Admin::setAdminID(string id) {
    adminID = id;
}

string Admin::getRole() {
    return role;
}

void Admin::setRole(string r) {
    role = r;
}

void Admin::manageUsers() {
}

void Admin::manageContent() {
}
