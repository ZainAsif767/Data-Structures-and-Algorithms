#include <stdlib.h>
#include <iostream>
using namespace std;
void insertionsort(int arr[], int length);
void printarray(int arr[], int size);

void insertionsort(int arr[], int length)
{
    int i, j, temp;
    for (i = 1; i < length; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << "Sorted array: ";
    printarray(arr, length);
}

void printarray(int arr[], int size)
{
    for (int j = 0; j < size; j++)
    {
        cout << " " << arr[j];
    }
    cout << endl;
}
int main()
{
    int arr[6] = {5, 1, 6, 2, 4, 3};
    insertionsort(arr, 6);
    return 0;
}