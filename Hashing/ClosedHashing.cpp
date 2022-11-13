#include <iostream>
using namespace std;

struct closehashing
{
    int HS, HI, load_factor;
    int *HT;
    closehashing()
    {
        load_factor = 0;
        HS = 10;
        HT = new int[HS];
        for (int i = 0; i < HS; i++)
        {
            HT[i] = -1;
        }
    }
    void Insert(int *arr, int length)
    {
        for (int i = 0; i < length; i++)
        {
            if (load_factor <= 0.5)
            {
                HI = arr[i] % HS;
                if (HT[HI] != -1)
                {
                    int j = HI;
                    while (HT[j] != -1)
                    {
                        j = (j + 1) % HS;
                    }
                    HT[j] = arr[i];
                }
                else
                {
                    HT[HI] = arr[i];
                }
            }
        }
    }
    int filledcells()
    {
        int count = 0;
        for (int i = 0; i < HS; i++)
        {
            if (HT[i] != -1)
            {
                count++;
            }
        }
        return count;
    }
    void display()
    {
        for (int i = 0; i < HS; i++)
        {
            cout << HT[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int arr[] = {1, 13, 16, 28, 19, 39};
    closehashing h;
    h.Insert(arr, 6);
    h.display();
    return 0;
}
