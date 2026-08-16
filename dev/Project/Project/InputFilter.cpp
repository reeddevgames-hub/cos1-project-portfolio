#include "InputFilter.h"
#include"ConsoleUtil.h"
#include<iostream>
 
int InputFilter::SafeInteger(const char* promptMessage, const char* errorMessage)
{
	int validatedValue;

	while(true)
	{
		ConsoleUtil::Write(promptMessage, Cyan);
		std::cin >> validatedValue;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			ConsoleUtil::WriteLine(errorMessage, Red);
			system("pause");

		}
		else
		{
			std::cin.ignore(1000, '\n');
			return validatedValue;
		}
	}
}

double InputFilter::SafePositiveDouble(const char* promptMessage, const char* errorMessage)
{
	double validatedMoney;

	while(true)
	{
		ConsoleUtil::Write(promptMessage, Cyan);
		std::cin >> validatedMoney;

		if (std::cin.fail() || validatedMoney <= 0.0)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			ConsoleUtil::WriteLine(errorMessage, Red);
			system("pause");

		}
		else
		{
			std::cin.ignore(1000, '\n');
			return validatedMoney;
		}
	}
}

std::string InputFilter::SafeString(const char* promptMessage, const char* errorMessage)
{
	std::string validatedText;

	while (true)
	{
		ConsoleUtil::Write(promptMessage, Cyan);
		std::getline(std::cin, validatedText);

		if (validatedText.empty())
		{
			ConsoleUtil::WriteLine(errorMessage, Red);
			system("pause");

		}
		else
		{
			return validatedText;
		}
	}
}