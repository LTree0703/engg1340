// Checkpoint 3.9: Reading input until -1
# include <iostream>
using namespace std;

int main()
{
    double i;
    double sumofinput = 0;
    double numofinput = 0;
    cin >> i;
    while (i != -1)
    {
        sumofinput += i;
        numofinput += 1;
        cin >> i;
    }
    cout << sumofinput / numofinput << endl;
}