#include<iostream>
#include<string>
using namespace std;

int main()
{
    int arr[5] = {5, 10, 85, 77, 44}, i;
    for (i = 0; i < 5; i++)
    {
        cout << "The value of arr : " << *(arr + i) << endl;
        cout << "The address of arr : " << (arr + 1) << endl;
    }
    return 0;
}