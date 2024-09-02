#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <chrono>
#include <iomanip>
#include "Input.h"

class Date{
    public:
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second=-1;
    
        Date();
        Date(int, int, int);
        std::string toText();
};

Date::Date(){
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* timeinfo = std::localtime(&currentTime);
    year=int(timeinfo->tm_year)+1900;
    month=int(timeinfo->tm_mon)+1;
    day=int(timeinfo->tm_mday);
    hour=int(timeinfo->tm_hour);
    minute=int(timeinfo->tm_min);
    second=int(timeinfo->tm_sec);
}

Date::Date(int Year, int Month, int Day){
    year=Year;
    month=Month;
    day=Day;
}

std::string Date::toText(){
    std::string s=input.getString(0+year)+"/"+input.getString(month)+"/"+input.getString(day);
    if(second!=-1) s=s+" "+input.getString(hour)+":"+input.getString(minute)+":"+input.getString(second);
    return s;
}

#endif