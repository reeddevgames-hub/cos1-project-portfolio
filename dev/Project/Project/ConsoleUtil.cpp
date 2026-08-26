#include "ConsoleUtil.h"

// Write to console a message in color and stay on that line.
void ConsoleUtil::Write(std::string message, ConsoleColor color)
{
    std::cout << "\033[" << color << "m" << message;
    std::cout << "\033[39m";
}

// Write to console a message in color and then go to the next line.
void ConsoleUtil::WriteLine(std::string message, ConsoleColor color)
{
    Write(message, color);
    std::cout << std::endl;
}

// Skip a line.
void ConsoleUtil::WriteLine()
{
    std::cout << std::endl;
}