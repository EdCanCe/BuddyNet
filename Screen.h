/*
* 
* BuddyNet - Screen Class
* A01645576
* This class has functions to retrieve
* screen data and render text according
* to the screen size.
*
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <regex>
#include "TextStyle.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

//Declaration of Screen Class
class Screen{
    //Declaration of Public Methods
    public:
        Text text;
        int getWidth();
        int getHeight();
        void clear();
        std::string centerHorizontal(std::string);
        //std::string centerVertical(std::string);
        //std::string center(std::string);
};

int Screen::getWidth(){
    #ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return columns;
    #else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
    #endif
}

int Screen::getHeight(){
    #ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return rows;
    #else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
    #endif
}

void Screen::clear(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

std::string Screen::centerHorizontal(std::string s){
    std::regex ansiCodes("\033\\[([0-9;]*m)");
    int n=std::regex_replace(s, ansiCodes, "").size(); //Size of string without ansi codes
    int width=getWidth();
    int dif=width-n;
    if(dif>=0){
        for(int i=0; i<dif/2; i++){
            s=" "+s;
        }
    }
    return s;
}

//Creates an Input object that will be used throughout the classes.
Screen screen;

#endif