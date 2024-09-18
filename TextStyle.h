/**
* 
* BuddyNet - TextStyle.h
* A01645576
* This file has functions to
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
    //Declaration of Public Methods
    public:

        /**
         * @brief Renders the given string into a black color.
         * 
         * @param text The text that will turn black.
         * @return std::string - The text rendered black.
         */
        std::string black(const std::string& text){
            return "\033[30m"+text+"\033[39m";
        }
        
        /**
         * @brief Renders the given string into a red color.
         * 
         * @param text The text that will turn red.
         * @return std::string - The text rendered red.
         */
        std::string red(const std::string& text){
            return "\033[31m"+text+"\033[39m";
        }

        /**
         * @brief Renders the given string into a green color.
         * 
         * @param text The text that will turn green.
         * @return std::string - The text rendered green.
         */
        std::string green(const std::string& text){
            return "\033[32m"+text+"\033[39m";
        }

        /**
         * @brief Renders the given string into a yellow color.
         * 
         * @param text The text that will turn yellow.
         * @return std::string - The text rendered yellow.
         */
        std::string yellow(const std::string& text){
            return "\033[33m"+text+"\033[39m";
        }

        /**
         * @brief Renders the given string into a blue color.
         * 
         * @param text The text that will turn blue.
         * @return std::string - The text rendered blue.
         */
        std::string blue(const std::string& text){
            return "\033[34m"+text+"\033[39m";
        }

        /**
         * @brief Renders the given string into a magenta color.
         * 
         * @param text The text that will magenta red.
         * @return std::string - The text rendered magenta.
         */
        std::string magenta(const std::string& text){
            return "\033[35m"+text+"\033[39m";
        }

        /**
         * @brief Renders the given string into a cyan color.
         * 
         * @param text The text that will turn cyan.
         * @return std::string - The text rendered cyan.
         */
        std::string cyan(const std::string& text){
            return "\033[36m"+text+"\033[39m";
        }

        /**
         * @brief Renders the given string into a white color.
         * 
         * @param text The text that will turn white.
         * @return std::string - The text rendered white.
         */
        std::string white(const std::string& text){
            return "\033[37m"+text+"\033[39m";
        }
};

/**
 * @class Style
 * 
 * @brief This class has functions that add the
 * ANSI escape code sequence to render styles.
 *
 */
class Style{
    //Declaration of Public Methods
    public:

        /**
         * @brief Renders the given string as bold.
         * 
         * @param text The text that will turn bold.
         * @return std::string - The text rendered bold.
         */
        std::string bold(const std::string& text){
            return "\033[1m" + text + "\033[22m";
        }

        /**
         * @brief Renders the given string, dimming it's colors.
         * 
         * @param text The text that will be dimmed.
         * @return std::string - The text rendered dim.
         */
        std::string dim(const std::string& text){
            return "\033[2m" + text + "\033[22m";
        }

        /**
         * @brief Renders the given string in italics.
         * 
         * @param text The text that will be italic.
         * @return std::string - The text rendered italic.
         */
        std::string italic(const std::string& text){
            return "\033[3m" + text + "\033[23m";
        }

        /**
         * @brief Renders the given string with an underline.
         * 
         * @param text The text that will get the underline.
         * @return std::string - The text rendered with the underline.
         */
        std::string underline(const std::string& text){
            return "\033[4m" + text + "\033[24m";
        }

        /**
         * @brief Renders the given string blinking.
         * 
         * @param text The text that will blink.
         * @return std::string - The text blinking.
         */
        std::string blinking(const std::string& text){
            return "\033[5m" + text + "\033[25m";
        }

        /**
         * @brief Renders the given string in reverse.
         * 
         * @param text The text that will reverse.
         * @return std::string - The text rendered in reverse.
         */
        std::string reverse(const std::string& text){
            return "\033[7m" + text + "\033[27m";
        }

        /**
         * @brief Renders the given string without being able to see it.
         * 
         * @param text The text that will turn hidden.
         * @return std::string - The text rendered hidden.
         */
        std::string hidden(const std::string& text){
            return "\033[8m" + text + "\033[28m";
        }

        /**
         * @brief Renders the given string with a strikethrough.
         * 
         * @param text The text that will get the strikethrough.
         * @return std::string - The text rendered sith the strikethrough.
         */
        std::string strikethrough(const std::string& text){
            return "\033[9m" + text + "\033[29m";
        }
};

/**
 * @class Background
 * 
 * @brief This class has functions that add the
 * ANSI escape code sequence to render backgrounds.
 *
 */
class Background{
    //Declaration of Public Methods
    public:

        /**
         * @brief Renders the given string with a black background.
         * 
         * @param text The text that will get the background.
         * @return std::string - The text rendered with the black background.
         */
        std::string black(const std::string& text){
            return "\033[40m"+text+"\033[49m";
        }
        
        /**
         * @brief Renders the given string with a red background.
         * 
         * @param text The text that will get the background.
         * @return std::string - The text rendered with the red background.
         */
        std::string red(const std::string& text){
            return "\033[41m"+text+"\033[49m";
        }

        /**
         * @brief Renders the given string with a green background.
         * 
         * @param text The text that will get the background.
         * @return std::string - The text rendered with the green background.
         */
        std::string green(const std::string& text){
            return "\033[42m"+text+"\033[49m";
        }

        /**
         * @brief Renders the given string with a yellow background.
         * 
         * @param text The text that will get the background.
         * @return std::string - The text rendered with the yellow background.
         */
        std::string yellow(const std::string& text){
            return "\033[43m"+text+"\033[49m";
        }

        /**
         * @brief Renders the given string with a blue background.
         * 
         * @param text The text that will get the background.
         * @return std::string - The text rendered with the blue background.
         */
        std::string blue(const std::string& text){
            return "\033[44m"+text+"\033[49m";
        }

        /**
         * @brief Renders the given string with a magenta background.
         * 
         * @param text The text that will get the background.
         * @return std::string - The text rendered with the magenta background.
         */
        std::string magenta(const std::string& text){
            return "\033[45m"+text+"\033[49m";
        }

        /**
         * @brief Renders the given string with a cyan background.
         * 
         * @param text The text that will get the background.
         * @return std::string - The text rendered with the cyan background.
         */
        std::string cyan(const std::string& text){
            return "\033[46m"+text+"\033[49m";
        }

        /**
         * @brief Renders the given string with a white background.
         * 
         * @param text The text that will get the background.
         * @return std::string - The text rendered with the white background.
         */
        std::string white(const std::string& text){
            return "\033[47m"+text+"\033[49m";
        }
};

/**
 * @class Text
 * 
 * @brief This class contains different classes
 * to manage text styling with only one class.
 *
 */
class Text{
    //Declaration of public attributes
    public:
        Color color; //Modifies the text color.
        Style style; //Modifies the text style.
        Background background; //Modifies the text background.
};

#endif