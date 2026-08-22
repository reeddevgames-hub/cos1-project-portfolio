#pragma once
#include<iostream>
#include <cstring>
#include<cctype>
namespace Helper 
{
	// ===================================================================================================================== //
	static bool IsInteger(char* letter) 
	{
		// letter is null pointer (empty), return false.
		if (letter == nullptr)
		{
			return false;
		}
		// else if string length is equal to 0, return false.
		else if (strlen(letter) == 0)
		{
			return false;
		}
		// if it passes both, move to checking if the sign is positive or negative
		else
		{

			int character = 0;
			// if sign check negative '-' or positive '+' is equal to letter[0] make the character input 1
			if (letter[ 0 ] == '-' || letter [ 0 ] == '+')
			{
				// if the string length is 1, return false
				if (strlen(letter) == 1)
				{
					return false;
				}
				// set character to 1 is there is a sign
				character = 1;
			}
			// set i to character value, then if i is less than the string length, increase the value of i by 1.
			for (int i = character; i < strlen(letter);i++) 
			{
				// check if 'i' is not a digit, if not, return false
				if (!isdigit(letter[ i ] ) ) {
					return false;
				}
			}
			// if it is a digit pass by the if statement and return true.
			return true;
		}
	}

	// ===================================================================================================================== //
	static void PrintIntegerBinary(int* num)
	{
		// if num is null pointer (empty), returns out of the function. 
		if (num == nullptr)
		{
			return;
		}
		// make a new value and dereference the num ptr.
		int value = *num;

		// mBitIndex counter starts at 31, if mBitIndex counter is greater than or equal to 0, mBitIndex decreases by one each loop.
		for (int mBitIndex = 31; mBitIndex >= 0; mBitIndex--)
		{
			// using bitwise shift the dereferenced num given to the value variable, the value shifts right by the mBitIndex, once the target value hits the first bit it stops.
			int bit = (value >> mBitIndex) & 1;
			std::cout << bit;
		}
		// start a new line.
		std::cout << std::endl;
	}

	// ===================================================================================================================== //
	static void BubbleSort(int* arr, int size)
	{
		// if arr is null pointer (empty), returns out of the function. 
		if (arr == nullptr)
		{
			return;
		}
		// else if the size is less than or equal to 1, return out of the function.
		else if (size <= 1)
		{
			return;
		}
		// when int i starts at 0, if i is less than the size value of the array minus 1, i adds by one incrementally. 
		for (int i = 0; i < size - 1; i++)
		{
			// when int j starts at 0, if j is less than the size value of the array minus the i value minus 1, j adds by one incrementally. 
			for (int j = 0; j < size - i - 1; j++)
			{
				// if the left array with index j is greater than the right array with index j+1, continue inside the if statement.
				if (arr[ j ] > arr[ j+1 ])
				{
					// make a new variable and tie it to the left array index arr[ j ].
					int arr1 = arr[ j ];

					// then switch the left array [ j ] with the right array [ j+1 ].
					arr[ j ] = arr[ j + 1 ];

					// then the right arr [ j + 1 ] is switched with the value arr1 
					arr[ j + 1 ] = arr1;
				}
			}
		}
	}

	// ===================================================================================================================== //
	static unsigned int GetMenuChoice(unsigned int min, unsigned int max)
	{
		unsigned int userValue;	

		// While the GetMenuChoice is true.
		while (true)
		{
			// promt user for min and max inputs and get userValue.
			std::cout << "Enter a choice (" << min << " - " << max << "): ";
			std::cin >> userValue;

			// if the value of the userValue is greater than or equal to the min and less than or equal to max, return the userValue.
			if(userValue >= min && userValue <= max)
			{
				return userValue;
			}
		}
	}

	// ===================================================================================================================== //
	static bool IsEven(int* num)
	{
		// If numis a nullptr or empty, return false.
		if (num == nullptr)
		{
			return false;
		}
		
		// Dereference the num pointer to an int variable value.
		int value = *num;

		// if the value variable is modular by 2, and the remainder is equal to 0, return true. If there is a remainder that is not 0, return false.
		if (value % 2 ==0) 
		{
			return true;
		}

		else
		{
			return false;
		}
	}
}