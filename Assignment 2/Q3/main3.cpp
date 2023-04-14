#include <iostream>
#include "d2boh.h"
using namespace std;

int main()
{
    int mode, input;
    cin >> mode >> input;
    switch (mode)
    {
        case 2:
            int output2[12];
            decimal_to_binary(input, output2);
            break;

        case 8:
            int output8[12];
            decimal_to_octal(input, output8);
            break;

        case 16:
            char output16[12];
            decimal_to_hexadecimal(input, output16);
            break;
    }
    return 0;
}