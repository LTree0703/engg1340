/*
Checkpoint 7.4 Reverse a string

You are given a program that reverses an input string.

Rewrite the reverse() function that uses recursion to reverse and return the string
*/
#include <iostream>
#include <string>

using namespace std;

/*
// iterative version
string reverse( string s )
{
	string r = "";

	for (int i = 0; i < s.length(); ++i)
		r = s[i] + r;

	return r;
}
*/


// recursive version?

string reverse(string s)
{
	if (s.length() == 0)
	{
		return s;
	}
	
	string r = "";
	if (r.length() != s.length())
	{
		r = s[s.length() - 1];
		s = s.substr(0, s.length() - 1);
		return r + reverse(s);
	}
	else
	{
		return r;
	}
}

int main()
{
	string s;
	cin >> s;

	cout << "String in reverse = " << reverse(s) << endl;
	return 0;
}