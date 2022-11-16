#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3, 4, 6, 1, 5};
    int x = 5;
    int n = sizeof(arr);
    int result = search(arr, n, x);
    (result == -1) ? cout << "Element not present" : cout << "Found at index: " << result;
}
