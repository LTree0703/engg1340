/*
Checkpoint 7.3 Report Daily Temperature
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Write a program to report the daily temperature given the hourly temperature of each day.

The temperature records[1] are stored in "temperature.txt". In this file, each line contains the date of the day followed by 24 hourly temperatures within the 24 hours.

Your program will read the data from "temperature.txt", calculate the average temperature and output the result to the file "average.txt" with each line containing the date and the average temperature (truncated to 1 decimal place) of the day.

You should assume that "temperature.txt" and "average.txt" are located to the directory where you write your .cpp file.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


int main() {
	ifstream tempFile("../temperature.txt");
	ofstream avgFile("average.txt");
	
	if (tempFile.is_open() && avgFile.is_open())
	{
		string tmp;
		int i = 0;
		double temp = 0.0;
		while (tempFile >> tmp)
		{	
		    if (i == 0)
			{
				avgFile << tmp << " ";
			}
			else if (i == 24)
			{
				temp += stod(tmp);
				avgFile << fixed << setprecision(1);
				avgFile << temp/24.0 << endl;
				temp = 0.0;
				i = -1;
			}
			else
			{
				temp += stod(tmp);
			}
			i++;
		}
	}
	else
	{
		cout << "Cannot open files" << endl;
		return 1;
	}

	tempFile.close();
	avgFile.close();
	return 0;
}