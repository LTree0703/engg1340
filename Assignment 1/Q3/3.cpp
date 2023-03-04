#include <iostream>
using namespace std;

char CaesarShift(char c, int k);

int main()
{
    char s;
    int k;
    cin >> s >> k;
    int k1, k2, k3;

    // read the input char s
    if (s == 'e') 
    {
        k1 = k / 10000;
        k2 = k % 10000 / 100;
        k3 = k % 100;
    }
    else if (s == 'd')
    {
        k1 = -k / 10000;
        k2 = -k % 10000 / 100;
        k3 = -k % 100;
    }
    else 
    {
        cout << "Invalid Input" << endl;
        return 0;
    }

    // read the input string and perform caesar shift for each char
    char c;
    int key = 0;
    while (true)
    {
        // mapping c to corresponding k(k1, k2, k3)
        if (key == 3)
        {
            key = 1;
        }
        else 
        {
            key++;
        }

        cin >> c;

        if (c == '!')
        {
            cout << c << endl;
            break;
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {   
            // handle three cases
            switch (key)
            {
                case 1:
                    cout << CaesarShift(c, k1) << " ";
                    break;
                case 2:
                    cout << CaesarShift(c, k2) << " ";
                    break;
                case 3:
                    cout << CaesarShift(c, k3) << " ";
                    break;
                default:
                    break;
            }
        }
        else
        {
            cout << c << " ";
        }
    }
}

char CaesarShift(char c, int k)
{
    int y; // define new_char y
    if (c >= 'A' && c <= 'Z') // uppercase
    {
        y = (c - 'A') + k % 26;
        // cout << y << endl;
        if (y < 0)
        {
            y += 26;
        }
        else if (y >= 26)
        {
            y -= 26;
        }
        return y + 'a';
    }
    else // lowercase
    {
        y = (c - 'a') + k % 26;
        // cout << y << endl;
        if (y < 0)
        {
            y += 26;
        }
        else if (y >= 26)
        {
            y -= 26;
        }
        return y + 'A';
    }
}