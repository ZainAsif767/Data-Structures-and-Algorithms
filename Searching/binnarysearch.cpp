#include <iostream>
using namespace std;

void binarysearch(int arr[], int x, int first, int last)
{
    int mid;

    if (last >= first)
    {
        mid = (first + last) / 2;
        if (arr[mid] == x)
        {
            cout << "found at index: " << mid + 1;
            // flag++;
            return;
        }
        if (arr[mid] > x)
        {

            return binarysearch(arr, x, first, mid - 1);
        }

        if (arr[mid] < x)
        {
            return binarysearch(arr, x, mid + 1, last);
        }
    }

    else
    {
        cout << "array is not sorted";
    }
}
int main()
{
    int arr[] = {1, 4, 6, 8, 9, 10, 20};
    int x = 2;
    int n = static_cast<int>(sizeof(arr)) / 4;
    cout << n;
    binarysearch(arr, x, 0, n - 1);
}