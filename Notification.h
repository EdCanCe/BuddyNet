/**
 * @file Notification.h
 * @author EdCanCe
 * @brief This file has the notificacions structures that will be
 * used to store the different types of notifications.
 * @version 0.1
 * @date 2024-09-18
 * 
 */
#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include "Date.h"
#include "Profile.h"
#include "Post.h"
#define ll long long int

class Notification{
    private:
        std::string text;
        Date date;
        int typeOfNotification; //The type of notification the user had. 0=Post comment, 1=Profile follower, 2=Post liked.
        bool interacted;
        Post* post;
        Profile* profile;

    public:
        Notification(std::string, int, Post*, Profile*);
        Notification(std::string, Date, int, bool, Post*, Profile*);
        std::string toText();
        void interact();
        Date& getDate();
        int getType();
        bool hasInteracted();
        Post& getPost();
        Profile& getProfile();
        void print();
};

Notification::Notification(std::string Text, int TypeOfNotification, Post* postPtr, Profile* profilePtr){
    text=Text;
    date=Date();
    typeOfNotification=TypeOfNotification;
    interacted=false;
    post=postPtr;
    profile=profilePtr;
}

Notification::Notification(std::string Text, Date notiDate, int TypeOfNotification, bool Interacted, Post* postPtr, Profile* profilePtr){
    text=Text;
    date=notiDate;
    typeOfNotification=TypeOfNotification;
    interacted=Interacted;
    post=postPtr;
    profile=profilePtr;
}

std::string Notification::toText(){
    return text;
}

void Notification::interact(){
    interacted=true;
}

Date& Notification::getDate(){
    return date;
}

int Notification::getType(){
    return typeOfNotification;
}

bool Notification::hasInteracted(){
    return interacted;
}

Post& Notification::getPost(){
    return *post;
}

Profile& Notification::getProfile(){
    return *profile;
}

#endif