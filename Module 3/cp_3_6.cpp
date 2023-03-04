// Checkpoint 3.6: Odd or Even?
#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    if (num % 2) 
    {
        cout << num << " is odd" << endl;
    }
    else
    {
        cout << num << " is even" << endl;
    }
    return 0;
}