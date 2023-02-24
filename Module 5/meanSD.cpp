// Checkpoint 5.8
# include <iostream>
# include <math.h>
using namespace std;

double cal_mean(double x[5]);
double cal_sd(double mean, double x[5]);

int main()
{
    double x1, x2, x3, x4, x5;
    cin >> x1 >> x2 >> x3 >> x4 >> x5;
    double x[5] = {x1, x2, x3, x4, x5};
    
    double mean = cal_mean(x);
    double sd = cal_sd(mean, x);

    printf("Mean = %.2f\n", mean);
    printf("Standard deviation = %.2f\n", sd);
}

double cal_mean(double x[5])
{
    double num = 0;
    for (int i = 0; i < 5; i++)
    {
        num += x[i];
    }
    return (num / 5.0);
}

double cal_sd(double mean, double x[5])
{
    double num = 0;
    for (int i = 0; i < 5; i++)
    {
        num += (x[i]-mean) * (x[i]-mean);
        cout << num << endl;
    }
    return sqrt(num / 5.0);
}