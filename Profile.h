#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>
#include "Date.h"
#define ll long long int

class Profile{
    private:
        ll id;
        std::string name;
        std::string username;
        std::string password;
        std::string description;
        Date birth;
    public:
        Profile(ll, std::string, std::string, std::string, std::string, int, int, int);
        ll getId();
        std::string getName();
        std::string getUsername();
        std::string getDescription();
        Date& getBirth();
        bool validatePassword(std::string Password);
        void setName(std::string);
        void setUsername(std::string);
        void setPassword(std::string);
        void setDescription(std::string);
};

Profile::Profile(ll Id, std::string Name, std::string Username, std::string Password, std::string Description, int year, int month, int day){
    id=Id;
    name=Name;
    username=Username;
    password=Password;
    description=Description;
    birth=Date(year, month, day);
}

ll Profile::getId(){
    return id;
}

std::string Profile::getName(){
    return name;
}

std::string Profile::getUsername(){
    return username;
}

std::string Profile::getDescription(){
    return description;
}

Date& Profile::getBirth(){
    return birth;
}

bool Profile::validatePassword(std::string Password){
    return password==Password;
}

void Profile::setName(std::string Name){
    name=Name;
}

void Profile::setUsername(std::string Username){
    username=Username;
}

void Profile::setPassword(std::string Password){
    password=Password;
}

void Profile::setDescription(std::string Description){
    description=Description;
}

#endif