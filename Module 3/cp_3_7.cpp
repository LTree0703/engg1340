// Checkpoint 3.7: Five-digit Integer
#include <iostream>
using namespace std;

int main()
{
    char num[5];
    cin >> num;
    for (int i = 0; i < 4; i++)
    {
        cout << num[i] << ",";
    }
    cout << num[4] << endl;
}