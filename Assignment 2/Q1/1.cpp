#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, pairs = 0;
    string card;
    cin >> n;

    bool numbers[13]; // outstanding move:)
    fill(numbers, numbers+13, false);

    for (int i = 0; i < n; i++)
    {
        cin >> card;
        int card_num = stoi(card.erase(0, 1));
        // cout << card_num << endl;
        // Searching for pairs
        if (numbers[card_num-1])
        {
            pairs++;
            // cout << "pairs" << pairs << endl;
            numbers[card_num-1] = false;
        }
        else
        {
            numbers[card_num-1] = true;
        }
    }
    cout << pairs << endl;
    return 0;
}
