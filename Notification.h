/**
 * @file Notification.h
 * @author EdCanCe
 * @brief This file has the notificacions structures that will be
 * used to store the different types of notifications.
 * @version 0.1
 * @date 2024-11-11
 * 
 */
#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include "Date.h"
#include "Profile.h"
#include "Post.h"
#define ll long long int

/**
 * @class Notification
 * 
 * This class has the methods and attributes of a notification.
 */
class Notification{
    private:
        std::string text; //The text of the nofitication
        Date date; //The date and time when it occured
        int typeOfNotification; //The type of notification the user had. 0=Post comment, 1=Profile follower, 2=Post liked.
        Post* post; //If is the comment it's the post of the comment.
        Profile* profile; //The profile that caused the notification

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

/**
 * @brief Constructs a Notification by giving it all of its
 * data except date.
 * 
 * @param Text The text of the notificacion.
 * @param TypeOfNotification The type of notification the 
 * user had. 0=Post comment, 1=Profile follower, 2=Post liked.
 * @param postPtr A pointer to the post that caused the notification.
 * @param profilePtr A pointer to the profile that caused the
 * notification.
 */
Notification::Notification(std::string Text, int TypeOfNotification, Post* postPtr, Profile* profilePtr){
    text=Text;
    date=Date();
    typeOfNotification=TypeOfNotification;
    post=postPtr;
    profile=profilePtr;
}

/**
 * @brief Constructs a Notification by giving it all of its
 * data includiung date.
 * 
 * @param Text The text of the notificacion.
 * @param Date The date when the notification ocurred.
 * @param TypeOfNotification The type of notification the 
 * user had. 0=Post comment, 1=Profile follower, 2=Post liked.
 * @param postPtr A pointer to the post that caused the notification.
 * @param profilePtr A pointer to the profile that caused the
 * notification.
 */
Notification::Notification(std::string Text, Date notiDate, int TypeOfNotification, Post* postPtr, Profile* profilePtr){
    text=Text;
    date=notiDate;
    typeOfNotification=TypeOfNotification;
    post=postPtr;
    profile=profilePtr;
}

/**
 * @brief Returns the text of the notification.
 * 
 * @return std::string - The text of the notification.
 */
std::string Notification::toText(){
    return text;
}

/**
 * @brief Returns the date of the notification.
 * 
 * @return Date& - The date of the notification.
 */
Date& Notification::getDate(){
    return date;
}

/**
 * @brief Returns the type of notification.
 * 0=Post comment.
 * 1=Profile follower.
 * 2=Post liked.
 * 
 * @return int - The type of notification.
 */
int Notification::getType(){
    return typeOfNotification;
}

/**
 * @brief Returns the post that caused the notification.
 * 
 * @return Post* - The pointer to the post.
 */
Post* Notification::getPost(){
    return post;
}

/**
 * @brief Returns the profile that caused the notification.
 * 
 * @return Profile* - The pointer to the profile.
 */
Profile* Notification::getProfile(){
    return profile;
}

/**
 * @brief Prints a notification
 * 
 */
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