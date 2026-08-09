#pragma once
#include <iostream>
#include<string>

enum ConsoleColor

// This is for any console utilities, such as coloring of headers and numbers.
{
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
    Default = 39
};

class ConsoleUtil
{
public:

    // Write to console a message in color and stay on that line.
    static void Write(std::string message, ConsoleColor color)
    {
        std::cout << "\033[" << color << "m" << message;
        std::cout << "\033[39m";
    }

    // Write to console a message in color and then go to the next line.
    static void WriteLine(std::string message, ConsoleColor color)
    {
        Write(message, color); 
        std::cout << std::endl;
    }

    // Skip a line.
    static void WriteLine() 
    {
        std::cout << std::endl;
    }
};