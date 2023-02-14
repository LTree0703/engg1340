# include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int b = 3;
    int c = 2;
    a += b += c;
    printf("%i %i %i\n", a, b, c);
    a *= b *= c;
    printf("%i %i %i\n", a, b, c);
    a += b %= c;
    printf("%i %i %i\n", a, b, c);
    (a += b) *= c;
    printf("%i %i %i\n", a, b, c);
}