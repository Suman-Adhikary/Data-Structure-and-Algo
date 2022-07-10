#include<iostream>
#include<string>
using namespace std;

int *func(int *p, int n)
{
    p = p+n;
    return p;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5}, n, *ptr;
    n = 5;
    ptr = func(arr, n);
    cout << arr << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    return 0;
}