#include <iostream>
using namespace std;

void search(int arr[], int n, int x)
{

    int flag = 0;
    int count = 0;
    int i = 0;
    while (i < n)
    {
        if (arr[i] != x)
        {
            i++;
            count++;
        }
        else
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        cout << "found at index: " << count + 1;

    else
        cout << "not found";
}

int main()
{

    int arr[] = {3, 4, 6, 1, 5};
    int x = 6;
    int n = sizeof(arr);
    search(arr, n, x);
}