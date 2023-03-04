/*
Checkpoint 6.5: Variance
Write a program to output the variance of up to 20 double precision floating point numbers which are inputted by the user.

Your program should first allow users to input how many numbers (maximum: 20) they want to calculate, 
then allows them to input the value of the numbers.

Please store the numbers inputted by the user in an array, and you are expected to have a function that receive the numbers (in array format), 
then calculates and returns the variance.

variance = (summation (x - μ)^2 ) / N
where μ is the mean of inputs and N is the number of inputs.

Example: The user wants to calculate the variance of 3 numbers which are 1,2,3.
Input:
3
1 2 3
Output:
Variance = 0.666667
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    double mean = 0;
    for (int i = 0; i < n; i++)
    {
        mean += arr[i];
    }
    mean = mean / n;

    double variance = 0;
    for (int i = 0; i < n; i++)
    {
        variance += (arr[i] - mean) * (arr[i] - mean);
    }

    variance = variance / n;
    cout << "Variance = " << variance << endl;
    return 0;
}
