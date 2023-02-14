# include <iostream>
using namespace std;

int main()
{
    char num[3];
    cin >> num;
    for (int i = 0; i < 3; i++)
    {
        cout << num[2-i];
    }
    cout << endl;
}