#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include "Screen.h"
#define ll long long int

class Input{
    public:
        ll getInt();
        ll getInt(ll, ll);
        ll getInt(std::string);
        std::string getString();
        std::string getString(ll);
        char getChar();
};

ll Input::getInt(){
    std::string s;
    std::getline(std::cin, s);
    ll li = s[0]=='-' ? 1 : 0;
    ll x=s.size();
    for(ll i=li; i<x; i++){
        if(s[i]<'0' || s[i]>'9'){
            std::cout<<screen.text.color.red("It must be a number\nTry again: ");
            std::getline(std::cin, s);
            li = s[0]=='-' ? 1 : 0;
            i=li-1;
            x=s.size();
        }
    }
    x=0;
    for(ll i=li; i<s.size(); i++){
        x*=10;
        x+=(s[i]-'0');
    }
    return s[0]=='-' ? x*-1 : x;
}

ll Input::getInt(ll a, ll b){
    if(a>b) std::swap(a,b);
    ll x;
    x=getInt();
    while(x<a || x>b){
        std::cout<<screen.text.color.red("The number must be between "+getString(a)+" and "+getString(b)+"\nTry again: ");
        x=getInt();
    }
    return x;
}

ll Input::getInt(std::string s){
    ll x=0;
    for(ll i=0; i<s.size(); i++){
        x*=10;
        x+=(s[i]-'0');
    }
    return x;
}

std::string Input::getString(){
    std::string s;
    std::getline(std::cin, s);
    return s;
}

std::string Input::getString(ll a){
    return std::to_string(a);
}

char Input::getChar(){
    std::string s;
    s=getString();
    while(s.size()>1){
        std::cout<<screen.text.color.red("Only enter one character: ");
        s=getString();
    }
    return s[0];
}

//Creates an Input object that will be used throughout the classes.
Input input;

#endif