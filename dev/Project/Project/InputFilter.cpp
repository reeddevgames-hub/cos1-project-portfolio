#include "InputFilter.h"
#include"ConsoleUtil.h"
#include<iostream>
 
int InputFilter::SafeInteger(const char* prompt_message, const char* error_message)
{
	int validated_value;

	while(true)
	{
		ConsoleUtil::Write(prompt_message, Cyan);
		std::cin >> validated_value;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			ConsoleUtil::WriteLine(error_message, Red);
			system("pause");

		}
		else
		{
			std::cin.ignore(1000, '\n');
			return validated_value;
		}
	}
}

double InputFilter::SafePositiveDouble(const char* prompt_message, const char* error_message)
{
	double validated_money;

	while(true)
	{
		ConsoleUtil::Write(prompt_message, Cyan);
		std::cin >> validated_money;

		if (std::cin.fail() || validated_money <= 0.0)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			ConsoleUtil::WriteLine(error_message, Red);
			system("pause");

		}
		else
		{
			std::cin.ignore(1000, '\n');
			return validated_money;
		}
	}
}

std::string InputFilter::SafeString(const char* prompt_message, const char* error_message)
{
	std::string validated_text;

	while (true)
	{
		ConsoleUtil::Write(prompt_message, Cyan);
		std::getline(std::cin, validated_text);

		if (validated_text.empty())
		{
			ConsoleUtil::WriteLine(error_message, Red);
			system("pause");

		}
		else
		{
			return validated_text;
		}
	}
}