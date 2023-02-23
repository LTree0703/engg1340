/*
   This program prints out the perfect numbers between 1 and N
*/

#include <iostream>
using namespace std;

const int N = 1000;

bool isPerfect(int num) 
{
	// find all divisors of num
	int sum_of_divisors = 0;
	for (int i = 1; i <= num/2; i++)
	{
		if (num % i == 0)
		{
			sum_of_divisors += i;
		}
	}
	return (sum_of_divisors == num);
}

int main()
{
	cout << "For the integers from 1 to " << N << ":\n";

	for (int j = 2; j <= N; ++j)
		if (isPerfect(j))
			cout << j << " is perfect\n";

	cout << endl;

	return 0;
}