/**
* 
* BuddyNet - Color Class
* A01645576
* This class has functions to
* help render many colors and
* styles.
*
*/
#ifndef TEXT_H
#define TEXT_H

#include <iostream>

/**
 * @class Color
 * 
 * @brief This class has functions that add the
 * ANSI escape code sequence to render colors.
 *
 */
class Color{
    public:
        //Renders the given text with a black color
        std::string black(const std::string& text){
            return "\033[30m"+text+"\033[39m";
        }
        
        //Renders the given text with a red color
        std::string red(const std::string& text){
            return "\033[31m"+text+"\033[39m";
        }

        std::string green(const std::string& text){
            return "\033[32m"+text+"\033[39m";
        }

        std::string yellow(const std::string& text){
            return "\033[33m"+text+"\033[39m";
        }

        std::string blue(const std::string& text){
            return "\033[34m"+text+"\033[39m";
        }

        std::string magenta(const std::string& text){
            return "\033[35m"+text+"\033[39m";
        }

        std::string cyan(const std::string& text){
            return "\033[36m"+text+"\033[39m";
        }

        std::string white(const std::string& text){
            return "\033[37m"+text+"\033[39m";
        }
};

class Style{
    public:
        std::string bold(const std::string& text){
            return "\033[1m" + text + "\033[22m";
        }

        std::string dim(const std::string& text){
            return "\033[2m" + text + "\033[22m";
        }

        std::string italic(const std::string& text){
            return "\033[3m" + text + "\033[23m";
        }

        std::string underline(const std::string& text){
            return "\033[4m" + text + "\033[24m";
        }

        std::string blinking(const std::string& text){
            return "\033[5m" + text + "\033[25m";
        }

        std::string reverse(const std::string& text){
            return "\033[7m" + text + "\033[27m";
        }

        std::string hidden(const std::string& text){
            return "\033[8m" + text + "\033[28m";
        }

        std::string strikethrough(const std::string& text){
            return "\033[9m" + text + "\033[29m";
        }
};

class Background{
    public:
        std::string black(const std::string& text){
            return "\033[40m"+text+"\033[49m";
        }
        
        std::string red(const std::string& text){
            return "\033[41m"+text+"\033[49m";
        }

        std::string green(const std::string& text){
            return "\033[42m"+text+"\033[49m";
        }

        std::string yellow(const std::string& text){
            return "\033[43m"+text+"\033[49m";
        }

        std::string blue(const std::string& text){
            return "\033[44m"+text+"\033[49m";
        }

        std::string magenta(const std::string& text){
            return "\033[45m"+text+"\033[49m";
        }

        std::string cyan(const std::string& text){
            return "\033[46m"+text+"\033[49m";
        }

        std::string white(const std::string& text){
            return "\033[47m"+text+"\033[49m";
        }
};

class Text{
    public:
        Color color;
        Style style;
        Background background;
};

#endif