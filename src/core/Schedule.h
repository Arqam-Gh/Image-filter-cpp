#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std;

class Schedule {
private:
    string scheduleID;
    string startTime;
    string endTime;

public:
    Schedule();
    ~Schedule();
    
    string getScheduleID();
    void setScheduleID(string id);
    string getStartTime();
    void setStartTime(string time);
    string getEndTime();
    void setEndTime(string time);
};

#endif
