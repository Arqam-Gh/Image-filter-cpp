#include "Schedule.h"
#include <iostream>
using namespace std;

Schedule::Schedule() : scheduleID(""), startTime(""), endTime("") {
}

Schedule::~Schedule() {
}

string Schedule::getScheduleID() {
    return scheduleID;
}

void Schedule::setScheduleID(string id) {
    scheduleID = id;
}

string Schedule::getStartTime() {
    return startTime;
}

void Schedule::setStartTime(string time) {
    startTime = time;
}

string Schedule::getEndTime() {
    return endTime;
}

void Schedule::setEndTime(string time) {
    endTime = time;
}
