# include <iostream>
using namespace std;

int main()
{
    double num, sum;
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        sum += num;
    }
    cout << sum / 5 << endl;
    
}