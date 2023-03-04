/*
Checkpoint 6.7: Palindrome
A palindrome is a string that is the same backward as it is forward. Write a program that lets a user enter a string and determine if it is a palindrome.

The function should output The input string is a palindrome. if the string is a palindrome and The input string is not a palindrome. otherwise.

However, your program should handle complications such as capitalization, spaces, and punctuation. For example, Madam, I'm Adam should be considered as a palindrome.

Hint: you may reduce the input string to madamimadam first and proceed with the checking.
*/

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    for (int i = 0, j = s.length()-1; i < s.length() && j >= 0; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    getline(cin, s);

    string tmp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            tmp += s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            tmp += (s[i] - 'A') + 'a';
        }
    }
    if (isPalindrome(tmp))
    {
        cout << "The input string is a palindrome." << endl;
    }
    else
    {
        cout << "The input string is not a palindrome." << endl;
    }
}