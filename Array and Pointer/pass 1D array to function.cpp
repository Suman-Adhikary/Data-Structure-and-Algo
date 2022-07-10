#include<iostream>
#include<string>
using namespace std;

void func(int arr[])
{
    int i;
    cout << "In func() : " << endl;
    for(i = 0; i < 5; i++)
    {
        arr[i] += 2;
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[5] = {10, 54, 67, 89, 44};
    func(arr);
    cout << "Inside main() : " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
        cout << sizeof(arr[i]) << endl;
    }

    return 0;
}