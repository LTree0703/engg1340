#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int foo(int arr[], int size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];
    
    int L = foo(arr, size/2);
    int R = foo(arr+size/2, size-size/2);
    arr[size-1] = L + R;
    return arr[size-1];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << foo(arr, 2) << " ";
    cout << foo(arr, 3) << " ";
    cout << foo(arr, 4) << " ";
    cout << foo(arr, 5) << " ";
    cout << endl;
    return 0;
}