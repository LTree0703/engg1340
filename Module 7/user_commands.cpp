/*
Checkpoint 7.5: Course Management System

You are given the skeleton program, which uses a while loop to process user commands repeatedly until the user input exit. Complete the program by adding functions to handle the following commands. See below table for the full set of commands.

You must use struct in this checkpoint.
*/

#include <iostream>
#include <string>
using namespace std;

struct Course {
	string courseCode;
	string courseName;
	string lecturer;
};

int main() {
	const int SIZE = 100;
	string input;
	cin >> input;

	Course course[SIZE];
	int courseTotal = 0;
	while (input != "exit") {
		if (input == "add") {
			// Add a course, the input contains the course code, the name and the lecturer. Each separated by a space and in a single word
			cin >> course[i].courseCode >> course[i].courseName >> course[i].lecturer;
			courseTotal++;
		}
		if (input == "show") {
			//  Find the course by course code and print the information.
			string target;
			cin >> target;
			for (int i = 0; i < courseTotal; i++) {
			    if (course[i].courseCode == target) {
                    cout << "Name: " << course[i].courseName << ", " << "Lecturer: " << course[i].lecturer << endl;
                }
            }
        }
		cin >> input;
	}
	return 0;
}