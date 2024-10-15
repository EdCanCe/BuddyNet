#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <chrono>
#include <iomanip>
#include "Input.h"

class Date{
    private:
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second; //Won't be printed, only used to sort the posts.
    
    public:
        Date();
        Date(int, int, int);
        Date(int, int, int, int, int, int);
        std::string toText();

        int getYear();
        int getMonth();
        int getDay();
        int getHour();
        int getMinute();
        int getSecond();
        friend bool operator<(const Date&, const Date&);
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
    hour=0;
    minute=0;
    second=-1;
}

Date::Date(int Year, int Month, int Day, int Hour, int Minute, int Second){
    year=Year;
    month=Month;
    day=Day;
    hour=Hour;
    minute=Minute;
    second=Second;
}

std::string Date::toText(){
    std::string s=input.getString(0+year)+"/"+input.getString(month)+"/"+input.getString(day);
    if(second!=-1) s=s+" "+input.getString(hour)+":"+input.getString(minute);
    return s;
}

int Date::getYear(){
    return year;
}

int Date::getMonth(){
    return month;
}

int Date::getDay(){
    return day;
}

int Date::getHour(){
    return hour;
}

int Date::getMinute(){
    return minute;
}

int Date::getSecond(){
    return second;
}

bool operator<(const Date& l, const Date& r){
    if (l.year != r.year) return l.year<r.year;
    if (l.month != r.month) return l.month<r.month;
    if (l.day != r.day) return l.day<r.day;
    if (l.hour != r.hour) return l.hour<r.hour;
    if (l.minute != r.minute) return l.minute<r.minute;
    return l.second<r.second;
}

#endif