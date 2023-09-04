#ifndef _FORMAT_HXX_
#define _FORMAT_HXX_

#include <iostream>
#include <string>

enum class ansi_color_code: int{
    black = 30,
    red = 31,
    green = 32,
    yellow = 33,
    blue = 34,
    magenta = 35, 
    cyan = 36,
    white = 37,
    background_black = 40,
    background_red = 41,
    background_green = 42,
    background_yellow = 43, 
    background_blue = 44,
    background_magenta = 45,
    background_cyan = 46,
    background_white = 47,
    bringht_black = 90,
    bringht_red = 91,
    bringht_green = 92,
    bringht_yellow = 93,
    bringht_blue = 94,
    bringht_magenta = 95,
    bringht_cyan = 96,
    bringht_white = 97,
};

template <typename printable>
std::string print_as_color(printable const &value, ansi_color_code color){
    std::stringstream sstr;
    sstr << "\033[1;" << static_cast<int>(color) << "m" << value << "\033[0m";
    return sstr.str();
};

template<ansi_color_code color, typename printable>
std::string print_as_color(printable const &value){
    std::stringstream sstr;
    sstr << "\033[1;" << static_cast<int>(color) << "m" << value << "\033[0m";
    return sstr.str();
};

#endif