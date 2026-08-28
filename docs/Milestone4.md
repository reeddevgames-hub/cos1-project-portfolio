# Milestone 4 - Final Project Documentation

## ⚙️ Final Features Added
* **Switched to Line-by-Line Reading**: I updated the InputFilter code to use std::getline. Making the code read line by line while providing more stable input parsing.
* **Strict Input Checking**: The code now checks inputs more thoroughly for example when the user types '965abc' instead of allowing the junk text to go through, it catcheds the text and rejects it.
* **Crash Prevention**: Wrapping the numerical conversion logic inside try-catch blocks allows the program to handle it gracefully if invalid symbols, or too big of numbers are entered.

## 🛠️ Refactoring Improvements
* **snake_case variable updates**: All variables that needed it were updated to use 'snake_case' code logic.
* **Cleaned up Duplicated Code**: Repetitive code loops and error messages were condensed into clean, reusable functions.
* **Removed cin.ignore**: I completely removed std::cin.ignore(1000, '\n') logic. Using std::getline naturally takes care of cleaning up the input buffer.

## 🐛 Bug Fixes & Usability Updates
* **Made It Run Everywhere**: I removed the Windows-only system("pause") command because it doesn't work on Macs or Linux. I replaced it with a private class function called pause_execution() so it works perfectly on any operating system.


