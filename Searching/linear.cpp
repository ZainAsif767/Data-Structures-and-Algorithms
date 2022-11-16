#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 6, 2, 1, 9};
    int n = static_cast<int>(sizeof(arr)) / 4;
    int x = 10;
    bool flag = false;
    cout << n;

    // cout << "enter element: ";
    // cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << "found at index: " << i + 1 << endl;
            flag = true;
            break;
        }
    }
    if (flag != true)
    {
        cout << "not found!";
    }
}
