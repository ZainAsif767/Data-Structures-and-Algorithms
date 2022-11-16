#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size)
{
    for (int i = size; i > 0; i--)
    {
        int j = 0;
        int temp;
        while (j <= i)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
    }
}
void display(int *arr, int size)
{
    for (int n = 0; n < size; n++)
    {
        cout << " " << arr[n];
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 8, 4, 5, 1, 3};
    int size = 6;
    bubbleSort(arr, size - 1);
    display(arr, size);
    return 0;
}
