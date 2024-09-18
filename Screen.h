/**
 * @file Screen.h
 * @author Edmundo Canedo Cervantes - A01645576
 * @brief This file has functions to retrieve
 * screen data and render text according
 * to the screen size.
 * @version 0.1
 * @date 2024-09-18
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

/**
 * @class Screen
 * 
 * @brief This class has functions that return
 * data corresponding to the screen, and also
 * helps to render text styling.
 *
 */
class Screen{
    //Declaration of Public Methods And Atrtributes
    public:
        Text text; //Attribute with the text class that enables text styling
        int getWidth();
        int getHeight();
        void clear();
        std::string center(std::string);
};

/**
 * @brief Looks up for the users console and gets it's width.
 * 
 * @return int - The width of the console.
 */
int Screen::getWidth(){
    #ifdef _WIN32 //Portion of code based on https://learn.microsoft.com/en-us/windows/console/small-rect-str
    CONSOLE_SCREEN_BUFFER_INFO csbi; //Gets the info of the current console
    int columns;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1; //Gets the coordinates of the console's margin and substracts them
    return columns;
    #else //Portion of code based on https://www.delorie.com/djgpp/doc/libc/libc_495.html
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
    #endif
}

/**
 * @brief Looks up for the users console and gets it's height.
 * 
 * @return int - The height of the console.
 */
int Screen::getHeight(){
    #ifdef _WIN32 //Portion of code based on https://learn.microsoft.com/en-us/windows/console/small-rect-str
    CONSOLE_SCREEN_BUFFER_INFO csbi; //Gets the info of the current console
    int rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; //Gets the coordinates of the console's margin and substracts them
    return rows;
    #else //Portion of code based on https://www.delorie.com/djgpp/doc/libc/libc_495.html
    struct winsize w; 
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
    #endif
}

/**
 * @brief Clears the screen.
 * 
 */
void Screen::clear(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

/**
 * @brief Centers a given string at the middle of the console.
 * 
 * @param s The string to center.
 * @return std::string The string centered.
 */
std::string Screen::center(std::string s){
     //Portion of code based on https://en.cppreference.com/w/cpp/regex/regex_replace
    std::regex ansiCodes("\033\\[([0-9;]*m)"); //Declares the ANSI escape codes pattern.
    int n=std::regex_replace(s, ansiCodes, "").size(); //Takes out all of the ANSI escape codes to only take into account the real text, and gets it's size. 
    int width=getWidth();
    int dif=width-n;
    if(dif>=0){ //Checks if the given string is bigger than the console width.
        for(int i=0; i<=dif/2; i++){ //Adds the needed spaces to center the text.
            s=" "+s;
        }
    }
    return s;
}

Screen screen; //Creates a screen object that will be used throughout the classes.

#endif