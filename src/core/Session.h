#ifndef SESSION_H
#define SESSION_H

#include <string>
using namespace std;

class Session {
private:
    string sessionID;
    string startTime;
    string endTime;

public:
    Session();
    ~Session();
    
    string getSessionID();
    void setSessionID(string id);
    string getStartTime();
    void setStartTime(string time);
    string getEndTime();
    void setEndTime(string time);
};

#endif
