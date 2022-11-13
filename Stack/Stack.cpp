#include <iostream>
using namespace std;

class Stack
{
public:
    int arr[10];
    // int top = -1;
    int i = -1;

    void push(int val)
    {
        if (i != 9)
        { // if space in arry available
            i++;
            arr[i] = val;
            // top++;
        }
        else
        {
            cout << "stack overflow \n";
        }
    }
    void display()
    {
        int j;
        for (j = 0; j <= i; j++)
        {
            cout << arr[j] << " ";
        }
    }
    void pop()
    {
        if (i != -1)
        { // agar stack top full ho
            int k;
            for (k = 1; k <= i; k++)
            {
                arr[k - 1] = arr[k];
            }
            i--;
        }
        else
        {
            cout << "Stack underflow \n";
        }
    }
};

int main()
{
    Stack s1;
    s1.push(12);
    s1.push(14);
    s1.push(3);
    s1.pop();
    // s1.pop();
    // s1.pop();
    // s1.pop();

    s1.display();
}
