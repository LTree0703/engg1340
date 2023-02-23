/*
   This program prompts the user to input a sequence of characters and outputs the number of vowels
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int numVowel = 0;
	char c;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		if (isVowel(c))
			numVowel++;
	}

	cout << "Number of vowels = " << numVowel << endl;

	return 0;
}