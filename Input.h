/**
 * @file Input.h
 * @author EdCanCe
 * @brief This file has the input methods to get data from the
 * user.
 * @version 0.1
 * @date 2024-11-11
 * 
 */
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include "Screen.h"
#define ll long long int

/**
 * @class Input
 * 
 * @brief This class has the methods to get data from inputs.
 */
class Input{
    public:
        ll getInt();
        ll getInt(ll, ll);
        ll getInt(std::string);
        std::string getString();
        std::string getString(ll);
        std::string getWord();
        std::string getPassword();
        std::string getRawString(std::string);
        char getChar();
};

/**
 * @brief Let's the user give an integer as input.
 * 
 * @return ll - The integer.
 */
ll Input::getInt(){
    std::string s;
    std::getline(std::cin, s);
    ll li = s[0]=='-' ? 1 : 0;
    ll x=s.size();
    for(ll i=li; i<x; i++){
        if(s[i]<'0' || s[i]>'9'){
            std::cout<<screen.text.color.red("It must be a number\n")+screen.text.style.italic(screen.text.color.green("Try again: "));
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

/**
 * @brief Let's the user give an integer as input between 2 values.
 * 
 * @return ll - The integer.
 */
ll Input::getInt(ll a, ll b){
    if(a>b) std::swap(a,b);
    ll x;
    x=getInt();
    while(x<a || x>b){
        std::cout<<screen.text.color.red("The number must be between "+getString(a)+" and "+getString(b)+"\n")+screen.text.style.italic(screen.text.color.green("Try again: "));
        x=getInt();
    }
    return x;
}

/**
 * @brief Transforms a string into a integer,
 * 
 * @return ll - The integer.
 */
ll Input::getInt(std::string s){
    ll x=0;
    for(ll i=0; i<s.size(); i++){
        x*=10;
        x+=(s[i]-'0');
    }
    return x;
}

/**
 * @brief Let's the user give a string as input.
 * 
 * @return std::string - The string.
 */
std::string Input::getString(){
    std::string s;
    std::getline(std::cin, s);
    return s;
}

/**
 * @brief Transforms an integer into a string.
 * 
 * @return std::string - The string.
 */
std::string Input::getString(ll a){
    return std::to_string(a);
}

/**
 * @brief Let's the user give a word as input.
 * 
 * @return std::string - The word.
 */
std::string Input::getWord(){
    std::string s=getString();
    for(ll i=0; i<s.size(); i++){
        if(s[i]==' '){
            std::cout<<screen.text.color.red("It cannot contain spaces\n")+screen.text.style.italic(screen.text.color.green("Try again: "));
            s=getString();
            i=0;
        }
    }
    return s;
}

/**
 * @brief Let's the user give a string as a hidden input.
 * 
 * @return std::string - The string.
 */
std::string Input::getPassword(){
    std::cout<<"\033[8m";
    std::string s;
    std::getline(std::cin, s);
    std::cout<<"\033[28m";
    return s;
}


/**
 * @brief Transforms the string into alphanumerical.
 * 
 * @return std::string - The string.
 */
std::string Input::getRawString(std::string s){
    std::string x="";
    char c;
    for(int i=0; i<s.size(); i++){
        c=s[i];
        if(c>='A' && c<='Z') x.push_back(std::tolower(c));
        else if((c>='a' && c<='z') || (c>='0' && c<='9')) x.push_back(c);
    }
    return x;
}

/**
 * @brief Let's the user give a char as input.
 * 
 * @return char - The char.
 */
char Input::getChar(){
    std::string s;
    s=getString();
    while(s.size()>1){
        std::cout<<screen.text.color.red("Only enterr one character\n")+screen.text.style.italic(screen.text.color.green("Try again: "));
        s=getString();
    }
    return s[0];
}

//Creates an Input object that will be used throughout the classes.
Input input;

#endif