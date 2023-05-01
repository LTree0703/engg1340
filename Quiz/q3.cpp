#include <iostream>
using namespace std;

int S(int n)
{
    int divisor_num = 1;
    for (int i = 1; i < n/2; i++)
    {
        if (n % i == 0)
        {
            divisor_num++;
        }
    }
    return divisor_num;
}

bool isAntiprime(int p)
{
    int s_p = S(p);
    for (int n = 1; n < p; n++)
    {
        if (S(n) >= s_p)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    if (n < 1)
    {
        cout << 1 << endl;
        return 0;
    }

    while (1)
    {
        if (isAntiprime(n))
        {
            cout << n << endl;
            break;
        }
        n++;
    }

    return 0;
}