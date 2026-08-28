#include "InputFilter.h"
#include"ConsoleUtil.h"
#include<iostream>
 
void InputFilter::pause_execution()
{
	ConsoleUtil::WriteLine("Press Enter to continue...", Red);
	std::string buffer;
	std::getline(std::cin, buffer);
}

int InputFilter::SafeInteger(const char* prompt_message, const char* error_message)
{
	std::string raw_input;

	while (true)
	{
		ConsoleUtil::Write(prompt_message, Cyan);
		std::getline(std::cin, raw_input);

		try {
			size_t processed_characters = 0;
			int combined_value = std::stoi(raw_input, &processed_characters);

			if (processed_characters == raw_input.length())
			{
				return combined_value;
			}
		}
		catch(const std::invalid_argument&){}
		catch(const std::out_of_range&){}

		ConsoleUtil::WriteLine(error_message, Red);
		pause_execution();
	}
}

double InputFilter::SafePositiveDouble(const char* prompt_message, const char* error_message)
{
	std::string raw_input;

	while (true)
	{
		ConsoleUtil::Write(prompt_message, Cyan);
		std::getline(std::cin, raw_input);

		try {
			size_t processed_characters = 0;
			double combined_value = std::stod(raw_input, &processed_characters);

			if (processed_characters == raw_input.length() && combined_value >= 0.0)
			{
				return combined_value;
			}
		}
		catch (const std::invalid_argument&) {}
		catch (const std::out_of_range&) {}

		ConsoleUtil::WriteLine(error_message, Red);
		pause_execution();
	}
}

std::string InputFilter::SafeString(const char* prompt_message, const char* error_message)
{
	std::string validated_text;

	while (true)
	{
		ConsoleUtil::Write(prompt_message, Cyan);
		std::getline(std::cin, validated_text);

		if (!validated_text.empty())
		{
			return validated_text;
		}
			ConsoleUtil::WriteLine(error_message, Red);
			pause_execution();
	}
}