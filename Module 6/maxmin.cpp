/*
Checkpoint 6.3 
Assume a 3D double array x is defined as:
double x[2][2][3] = { { {3, 4, 2}, {0, -3, 9} }, { {13, 4, 56}, {5, 9, 3}}}; 

Write a program that would find the maximum and minimum values in this 2-by-2-by-3 double array x. 
Print the maximum and minimum value after they are found.
*/

#include <iostream>
using namespace std;

void finding_max_min(double x[2][2][3])
{
    double max, min;
    // brute-force approach
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (x[i][j][k] > max)
                {
                    max = x[i][j][k];
                }
                if (x[i][j][k] < min)
                {
                    min = x[i][j][k];
                }
            }
        }
    }
    cout << max << " " << min << endl;
}

int main()
{
    double x[2][2][3] = { { {3, 4, 2}, {0, -3, 9} }, { {13, 4, 56}, {5, 9, 3}}}; 
    finding_max_min(x);
    return 0;
}