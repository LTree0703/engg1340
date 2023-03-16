// d2boh.cpp

#include <iostream>
#include "d2boh.h"
using namespace std;

int decimal_to_binary(int input, int output[10]) {

	int count = 0;
	int factor = 2;

	while (input > 0)
	{
		output[count] = input % factor;
		input /= factor;
		// cout << "output = " << output[i] << " " << "input = " << input << endl;
		count++;
	}
	
	int tmp;
	if (output[count-1] == 0)
	{
		tmp = count-2;
	}
	else
	{
		tmp = count-1;
	}
	
	for (int i = tmp; i >= 0; i--)
	{
		cout << output[i];
	}
	return count;
}

int decimal_to_octal(int input, int output[10]) {
	int count = 0;
	int factor = 8;

	while (input > 0)
	{
		output[count] = input % factor;
		input /= factor;
		// cout << "output = " << output[i] << " " << "input = " << input << endl;
		count++;
	}

	int tmp;
	if (output[count-1] == 0)
	{
		tmp = count-2;
	}
	else
	{
		tmp = count-1;
	}
	
	for (int i = tmp; i >= 0; i--)
	{
		cout << output[i];
	}
	return count;
}

int decimal_to_hexadecimal(int input, char output[10]) {
	int count = 0;
	int factor = 16;

	while (input > 0)
	{
		int tmp = input % factor;
		if (tmp >= 10)
		{
			output[count] = 'A' + tmp - 10;
		}
		else
		{
			output[count] = '0' + tmp;
		}
		input /= factor;
		// cout << "output = " << output[i] << " " << "input = " << input << endl;
		count++;
	}
	
	int tmp;
	if (output[count-1] == 0)
	{
		tmp = count-2;
	}
	else
	{
		tmp = count-1;
	}
	
	for (int i = tmp; i >= 0; i--)
	{
		cout << output[i];
	}
	return count;
}