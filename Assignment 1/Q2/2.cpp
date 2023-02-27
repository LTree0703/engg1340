# include <iostream>
using namespace std;

bool isComposite(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int M, N;
    cin >> M >> N;
    for (int i = M; i <= N; i++)
    {
        if (isComposite(i))
        {
            cout << i << endl;
        }
    }
}