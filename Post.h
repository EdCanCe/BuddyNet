#ifndef POST_H
#define POST_H

#include <iostream>
#include "Profile.h"
#include "Date.h"
#define ll long long int

class Post{
    private:
        ll id;
        Profile* author;
        std::string text;
        Date date;
        Post* fatherPost; //Father post in case it's a comment - Future implementation
    public:
        Post(ll, Profile&, std::string);
        ll getId();
        Profile& getAuthor();
        std::string getText();
        Date& getDate();
};

Post::Post(ll Id, Profile& Author, std::string Text){
    id=Id;
    author=&Author;
    text=Text;
    date=Date();
}

ll Post::getId(){
    return id;
}

Profile& Post::getAuthor(){
    return *author;
}

std::string Post::getText(){
    return text;
}

Date& Post::getDate(){
    return date;
}

#endif