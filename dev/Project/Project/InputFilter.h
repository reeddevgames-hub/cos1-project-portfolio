#pragma once
#include<string>

// This class will be used to make sure that the user inputs the right symboles, letters or, numbers,
// so the console application does not crash.
class InputFilter
{
public:
	// Will be used to filter out any invalid inputs (like letters) and loop till a proper integer is accepted. 
	static int SafeInteger(const char* prompt_message, const char* error_message);

	// Will be used to filter out any invalid inputs for doubles such as letters and numbers less than zero, and loop till a positive double is accepted. 
	static double SafePositiveDouble(const char* prompt_message, const char* error_message);

	// Will be used to filter out any invalid inputs and loop till a string input is accepted. 
	static std::string SafeString(const char* prompt_message, const char* error_message);

private:

	// Replacement for the nostant system("pause")
	static void pause_execution();
};

