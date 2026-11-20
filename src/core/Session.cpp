#include "Session.h"
#include <iostream>
using namespace std;

Session::Session() : sessionID(""), startTime(""), endTime("") {
}

Session::~Session() {
}

string Session::getSessionID() {
    return sessionID;
}

void Session::setSessionID(string id) {
    sessionID = id;
}

string Session::getStartTime() {
    return startTime;
}

void Session::setStartTime(string time) {
    startTime = time;
}

string Session::getEndTime() {
    return endTime;
}

void Session::setEndTime(string time) {
    endTime = time;
}
