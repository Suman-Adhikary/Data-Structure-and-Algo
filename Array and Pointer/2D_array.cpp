#include<iostream>
using namespace std;

int main()
{
    int arr[3][4], i, j;
    cout << "Enter the elements : " << endl;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "The matrix is  : " << endl;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}   