#include <iostream>
using namespace std;

class Queue
{

public:
    int s = 10;
    int head, tail;
    int *arr;
    Queue()
    {
        // cout << "Enter size for Queue: ";
        // cin >> s;
        arr = new int[s];
        tail = 0;
        head = -1;
    }
    void enqu(int val);
    void dequ();
    void display();
};
void Queue::enqu(int val)
{
    head++;
    if (head == s)
    {
        cout << "queue overflow";
        return;
    }
    for (int i = head; i >= 0; i--)
    {
        if (i == 0)
        {
            arr[i] = val;
            continue;
        }
        arr[i] = arr[i - 1];
    }
}
void Queue::dequ()
{
    if (head == -1)
    {
        cout << " queue is empty";
        return;
    }
    head--;
}
void Queue::display()
{
    for (int i = 0; i <= head; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    Queue q1 = Queue();
    q1.enqu(11);
    q1.enqu(23);
    q1.enqu(6);
    q1.enqu(4);
    // q1.dequ();
    q1.display();
    return 0;
}
