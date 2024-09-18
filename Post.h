/**
 * @file Post.h
 * @author Edmundo Canedo Cervantes - A01645576
 * @brief This file contains the Post class, that manages
 * the posts data.
 * @version 0.1
 * @date 2024-09-18
 * 
 */
#ifndef POST_H
#define POST_H

#include <iostream>
#include "Profile.h"
#include "Date.h"
#include "Screen.h"
#define ll long long int

/**
 * @class Post
 * 
 * @brief 
 * 
 */
class Post{
    private:
        ll id;
        Profile* author;
        std::string text;
        Date date;
        ll votes;
        Post* fatherPost = NULL; //Father post in case it's a comment - Future implementation
    public:
        Post(ll, Profile&, std::string);
        Post(ll, Profile&, ll, std::string);
        ll getId();
        Profile& getAuthor();
        std::string getText();
        Date& getDate();
        ll getVotes();
        void print();
};

Post::Post(ll Id, Profile& Author, std::string Text){
    id=Id;
    author=&Author;
    votes=0;
    text=Text;
    date=Date();
}

Post::Post(ll Id, Profile& Author, ll Votes, std::string Text){
    id=Id;
    author=&Author;
    votes=Votes;
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

ll Post::getVotes(){
    return votes;
}

void Post::print(){
    int width=screen.getWidth();
    for(int i=0; i<width; i++){
        std::cout<<screen.text.style.dim("═");
    }
    std::cout<<"\n"<<screen.center(screen.text.style.bold(screen.text.color.green("@"+author->getUsername())));
    std::cout<<"\n"<<screen.center(screen.text.color.green(author->getName()));
    std::cout<<"\n"<<screen.center("Votes: " + (votes >= 0 ? screen.text.color.green(input.getString(votes)) : screen.text.color.red(input.getString(votes))) + "   |   " + date.toText())<<"\n";
    for(int i=0; i<width; i++){
        std::cout<<screen.text.style.dim("─");
    }
    std::cout<<"\n"<<text<<"\n";
    for(int i=0; i<width; i++){
        std::cout<<screen.text.style.dim("═");
    }
}

#endif