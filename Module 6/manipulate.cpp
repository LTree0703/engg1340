/*
Checkpoint 6.4: Array manipulation
Write a program (C++) that takes an input number i, then perform the following:

    Declare an array which contains 15 integers.
    Initialize the array so that the first i elements are assigned with a value that equals to the square of the index variable. 
    Initialize 15 elements only if i is greater than 15.
    The next 5 elements, if available, are assigned with value 0
    While the remaining elements (if any) are assigned with a value that equals to 3 to the power of the index value.
    Output the elements in the array, with a separation of space between each element.

Your program could assumes that input value is always greater than 0.
*/
#include <iostream>
#include <math.h>
using namespace std;

const int n = 15;
int main()
{
    int i;
    int arr[n];
    cin >> i;
    if (i < 15)
    {
        for (int j = 0; j < i; j++)
        {
            arr[j] = j * j;
        }
        for (int j = i; j < i+5; j++)
        {
            arr[j] = 0;
        }
        if (i < 10)
        {
            for (int j = i + 5; j < n; j++)
            {
                arr[j] = pow(3, j);
            }
        }
    }
    else 
    {
        for (int j = 0; j < n; j++)
        {
            arr[j] = j * j;
        }
    }
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
}