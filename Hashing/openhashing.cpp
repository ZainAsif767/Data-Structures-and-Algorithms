#include <iostream>
using namespace std;

struct node
{
    int key;
    node *next;
    node()
    {
        next = NULL;
    }
    node(int val)
    {
        this->key = val;
        next = NULL;
    }
};

struct openhashing
{
    int HS, HI;
    node *HT;
    openhashing()
    {
        HS = 10;
        HT = new node[HS];
    }
    void Insert(int *arr, int length)
    {
        for (int i = 0; i < length; i++)
        {
            HI = arr[i] % HS;
            if (HT[HI].next == NULL)
            {
                node *n = new node(arr[i]);
                HT[HI].next = n;
            }
            else
            {
                node *curr_node = HT[HI].next;
                while (curr_node->next != NULL)
                {
                    curr_node = curr_node->next;
                }
                node *n = new node(arr[i]);
                curr_node->next = n;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < HS; i++)
        {
            if (HT[i].next == NULL)
            {
                cout << 0 << endl;
            }
            else
            {
                node *curr_node = HT[i].next;
                cout << curr_node->key << " ";
                while (curr_node->next != NULL)
                {
                    curr_node = curr_node->next;
                    cout << curr_node->key << " ";
                }
                cout << endl;
            }
        }
    }
};
int main()
{
    int arr[] = {100, 44, 5, 2, 13, 33, 15, 66, 99, 88};
    openhashing h;
    h.Insert(arr, 10);
    h.display();
    return 0;
}
