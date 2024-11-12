/**
 * @file Date.h
 * @author EdCanCe
 * @brief This file has the date class that manages time and dates.
 * @version 0.1
 * @date 2024-11-11
 * 
 */
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <chrono>
#include <iomanip>
#include "Input.h"

/**
 * @class Date
 * 
 * @brief This class contains the methods and attributes
 * of a date.
 */
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

/**
 * @brief Constructs the current Date.
 * 
 */
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

/**
 * @brief Construct a new Date without time.
 * 
 * @param Year (in the format 19XX - 20XX)
 * @param Month 
 * @param Day 
 */
Date::Date(int Year, int Month, int Day){
    year=Year;
    month=Month;
    day=Day;
    hour=0;
    minute=0;
    second=-1;
}

/**
 * @brief Construct a new Date with time.
 * 
 * @param Year (in the format 19XX - 20XX)
 * @param Month 
 * @param Day 
 * @param Hour 
 * @param Minute 
 * @param Second 
 */
Date::Date(int Year, int Month, int Day, int Hour, int Minute, int Second){
    year=Year;
    month=Month;
    day=Day;
    hour=Hour;
    minute=Minute;
    second=Second;
}

/**
 * @brief Turns the date to text format.
 * 
 * @return std::string - The date as string.
 */
std::string Date::toText(){
    std::string s=input.getString(0+year)+"/"+input.getString(month)+"/"+input.getString(day);
    if(second!=-1) s=s+" "+input.getString(hour)+":"+input.getString(minute);
    return s;
}

/**
 * @brief Returns the year of the date.
 * 
 * @return int - The year of the date(19XX-20XX).
 */
int Date::getYear(){
    return year;
}

/**
 * @brief Returns the month of the date.
 * 
 * @return int - The month of the date.
 */
int Date::getMonth(){
    return month;
}

/**
 * @brief Returns the day of the date.
 * 
 * @return int - The day of the date.
 */
int Date::getDay(){
    return day;
}

/**
 * @brief Returns the hour of the date.
 * 
 * @return int - The hour of the date.
 */
int Date::getHour(){
    return hour;
}

/**
 * @brief Returns the minute of the date.
 * 
 * @return int - The minute of the date.
 */
int Date::getMinute(){
    return minute;
}

/**
 * @brief Returns the second of the date.
 * 
 * @return int - The second of the date.
 */
int Date::getSecond(){
    return second;
}

/**
 * @brief Compares two dates to get which one of them is older.
 * 
 * @param l The first date.
 * @param r The second date.
 * @return TRUE - The first date is older.
 * 
 * FALSE - The second date is older.
 */
bool operator<(const Date& l, const Date& r){
    if (l.year != r.year) return l.year<r.year;
    if (l.month != r.month) return l.month<r.month;
    if (l.day != r.day) return l.day<r.day;
    if (l.hour != r.hour) return l.hour<r.hour;
    if (l.minute != r.minute) return l.minute<r.minute;
    return l.second<r.second;
}

#endif