#include <iostream>
#include <vector>
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
    void Insert(vector<int> arr)
    {
        int filledcells = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            load_factor = float(filledcells) / float(HS);
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
                    filledcells++;
                }
                else
                {
                    HT[HI] = arr[i];
                    filledcells++;
                }
            }
            else
            {
                HS = HS * 2;
                delete[] HT;
                HT = NULL;
                int *newHT = new int[HS];
                for (int i = 0; i < HS; i++)
                {
                    newHT[i] = -1;
                }
                HT = newHT;
                i = -1;
                filledcells = 0;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < HS; i++)
        {
            cout << HT[i] << " ";
        }
        cout << endl;
    }
    ~closehashing()
    {
        delete[] HT;
        HT = NULL;
    }
};
int main()
{
    vector<int> arr = {19, 9, 29, 39, 1, 2, 3, 4, 5, 10, 77};
    closehashing h;
    h.Insert(arr);
    h.display();
    return 0;
}
