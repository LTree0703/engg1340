/*
Checkpoint 6.6: Replace the occurences
Write a program that read three input strings and replaces all the occurrences of the second string with the third string in the first string.

The first input string may contain spaces, but you can assume the second and the third input are a single word (No spaces).

Hint: Use getline() instead of cin when necessary.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, old_s, new_s;
    getline(cin, s);
    getline(cin, old_s);
    getline(cin, new_s);

    // find all the occurences
    string tmp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s.substr(i, old_s.length()) == old_s)
        {
            tmp += new_s;
            i += old_s.length()-1;
        }
        else
        {
            tmp += s[i];
        }
    }
    cout << tmp << endl;
    return 0;
}