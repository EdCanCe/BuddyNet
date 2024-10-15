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
        Post* post; //If is the comment it's the post of the comment.
        Profile* profile;

    public:
        Notification(std::string, int, Post*, Profile*);
        Notification(std::string, Date, int, Post*, Profile*);
        std::string toText();
        Date& getDate();
        int getType();
        Post* getPost();
        Profile* getProfile();
        void print();
};

Notification::Notification(std::string Text, int TypeOfNotification, Post* postPtr, Profile* profilePtr){
    text=Text;
    date=Date();
    typeOfNotification=TypeOfNotification;
    post=postPtr;
    profile=profilePtr;
}

Notification::Notification(std::string Text, Date notiDate, int TypeOfNotification, Post* postPtr, Profile* profilePtr){
    text=Text;
    date=notiDate;
    typeOfNotification=TypeOfNotification;
    post=postPtr;
    profile=profilePtr;
}

std::string Notification::toText(){
    return text;
}

Date& Notification::getDate(){
    return date;
}

int Notification::getType(){
    return typeOfNotification;
}

Post* Notification::getPost(){
    return post;
}

Profile* Notification::getProfile(){
    return profile;
}

void Notification::print(){
    int width=screen.getWidth();
    for(int i=0; i<width; i++){
        std::cout<<screen.text.style.bold(screen.text.color.green("═"));
    }
    std::cout<<"\n";

    if(typeOfNotification==0){ //Post comment
        std::cout<<screen.center(screen.text.style.bold("YOU'VE RECIVED A COMMENT!"))<<"\n";
    }else if(typeOfNotification==1){ //Profile follower
        std::cout<<screen.center(screen.text.style.bold("YOU'VE GOTTEN A FOLLOWER!"))<<"\n";
    }else{ //Post liked
        std::cout<<screen.center(screen.text.style.bold("YOU'VE GOTTEN A VOTE!"))<<"\n";
    }
    std::cout<<screen.center(text)<<"\n";
    std::cout<<screen.center(date.toText());

    std::cout<<"\n";
    for(int i=0; i<width; i++){
        std::cout<<screen.text.style.bold(screen.text.color.green("═"));
    }
}

#endif