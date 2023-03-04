// Checkpoint 3.8: BMI Calculator
#include <iostream>
using namespace std;

int main()
{
    float weight;
    float height;
    cin >> weight >> height;
    float bmi = weight / (height * height);
    cout << "Your BMI = " << bmi << endl;
    cout << "BMI VALUES\nUnderweight: less than 18.5\nNormal: between 18.5 and 24.9\nOverweight: between 25 and 29.9\nObese: 30 or greater" << endl;
}