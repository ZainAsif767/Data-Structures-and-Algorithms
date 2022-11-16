#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 6, 2, 1, 9};
    int n = sizeof(arr);
    int x;

    cout << "enter element: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << "found at index: " << i + 1 << endl;
            break;
        }
    }
}
