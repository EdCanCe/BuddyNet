/**
 * @file Search.h
 * @author EdCanCe
 * @brief This file has the search structures that will be
 * used to store the different types of searches.
 * @version 0.1
 * @date 2024-09-18
 * 
 */
#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>

class Search{
    private:
        std::string text;
        bool typeOfSearch; //The type of search the user made. False=Post, True=Profile

    public:
        Search(std::string, bool);
        std::string toText();
        bool getType();
};

Search::Search(std::string Text, bool TypeOfSearch){
    text=Text;
    typeOfSearch=TypeOfSearch;    
}

std::string Search::toText(){
    return text;
}

bool Search::getType(){
    return typeOfSearch;
}

#endif