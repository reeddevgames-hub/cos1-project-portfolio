#pragma once
#include <iostream>
#include<string>

// This is for any console utilities, such as coloring of headers and numbers.
enum ConsoleColor
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

    static void Write(std::string message, ConsoleColor color);

    static void WriteLine(std::string message, ConsoleColor color);

    static void WriteLine();
};