#include "ConsoleUtil.h"

// Write to console a message in color and stay on that line.
void ConsoleUtil::Write(std::string message_text, ConsoleColor text_color)
{
    std::cout << "\033[" << text_color << "m" << message_text;
    std::cout << "\033[39m";
}

// Write to console a message in color and then go to the next line.
void ConsoleUtil::WriteLine(std::string message_text, ConsoleColor text_color)
{
    Write(message_text, text_color);
    std::cout << std::endl;
}

// Skip a line.
void ConsoleUtil::WriteLine()
{
    std::cout << std::endl;
}