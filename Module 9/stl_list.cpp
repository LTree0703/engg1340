/*
Checkpoint 9.1: STL list
Write a program to implement a simple student record system by using STL list that has the following functions:

When the program starts, it should wait for user’s command. You can assume there are only 3 valid commands for the user to input (Add, Search or Quit).

    When the user input the command “Add”, the program should allow him/her to add a new student record. The user should first input the command “Add”, followed by the student’s name, the student’s major and the student number. The information should then be stored in a STL list. When the insert is finished, it should output “Added Successfully”.
    When the user input the command “Search”, the program should allow him/her to find the student number from the student’s name and the student’s major. The user should first input the command “Search”, followed by the student’s name and the student’s major. If there is a match between the student’s name and the student’s major inputted by the user and the student’s name and major stored in the STL list, it should output the student number in the format of “Student Number:<the student number found>”. If there’s no such matching, it should output “No Record found”.

Please note that after the above function is executed, the program will wait for the user’s next command until he/she input the command “Quit”. The program will output “Bye” and be terminated once it receives the command “Quit”.

You can assume the user would NOT input any invalid command and always follow the input format as described above.
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
using namespace std;

int main()
{
    map<list<string>, string> stdRecords;
    string func, name, major, uid;
    while (cin >> func)
    {
        if (func == "Quit")
        {
            cout << "Bye" << endl;
            return 0;
        }
        else if (func == "Add")
        {
            cin >> name >> major >> uid;
            stdRecords[{name, major}] = uid;
            cout << "Added successfully" << endl;
        }
        else if (func == "Search")
        {
            cin >> name >> major;
            map<list<string>, string>::iterator itr;
            bool found = false;
            for (itr = stdRecords.begin(); itr != stdRecords.end(); itr++)
            {
                list<string> li = {name, major};
                if ((*itr).first == li)
                {
                    found = true;
                    cout << "Student Number: " << (*itr).second << endl;
                    break;
                }
            }
            if (!found)
                cout << "No Record found" << endl;
        }
    }
}