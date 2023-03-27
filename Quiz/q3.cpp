#include <iostream>
using namespace std;

int S(int n)
{
    int count = 1;
    for (int i = 1; i < n/2; i++)
    {
        if (n%i == 0)
        {
            count++;
        }
    }
    return count;
}

bool isAntiprime(int p)
{
    int sp = S(p);
    for (int i = 1; i < p; i++)
    {
        if (S(i) > sp)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int b;
    cin >> b;
    if (b <= 0)
    {
        cout << 1 << endl;
        return 0;
    }
    int p = b;
    while (!isAntiprime(p))
    {
        p++;
    }
    cout << p << endl;
    return 0;
}