#include <iostream>

using namespace std;

int reverse(int N) {
    // Several missing statements
    int r, rev = 0;
    int m = abs(N);
    while (m != 0)
    {
        r = m % 10;
        rev = rev * 10 + r;
        m /= 10;
    }
    if (N < 0)
    {
        return rev;
    }
    else
    {
        return -rev;
    }
}

int main() {
    int N;
    cin >> N;
    cout << reverse(N) << endl;
    return 0;
}