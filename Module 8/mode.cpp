/*
Checkpoint 8.1: The mode of the set
The mode of a data set is the number that occurs most frequently in the set.

Write a program to find the mode of the set that is inputted by the user. Your program should use a dynamic array to store the user input. After printing the result, your program should release the memory allocated to the dynamic array.

You could assume that there is always one and only one mode in the input set.
*/

#include <iostream>
using namespace std;

int main()
{
    int set_size = 0;
    cin >> set_size;
    int i, *set;
    set = new int[set_size];
    for (i = 0; i < set_size; i++)
    {
        cin >> set[i]; 
    }
    
    
    int mode = 0;
    int target;
    for (i = 0; i < set_size; i++)
    {
        int count = 1;
        for (int j = 0; j < set_size; j++)
        {
            if (set[i] == set[j] && i != j)
            {
                count++;
            }
        }
        if (count > mode)
        {
            mode = count;
            target = set[i];
        }
    }
    delete[] set;
    cout << "The mode of the set is " << target << endl;
    return 0;
}