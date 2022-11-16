#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
    node()
    {
        this->next = NULL;
    }
    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
node *enque(node *root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
    }
    else
    {
        root->next = enque(root->next, val);
    }
    return root;
}
node *deque(node *root)
{
    if (root->next == NULL)
    {
        delete root;
        return NULL;
    }
    root->next = deque(root->next);
    return root;
}
void display(node *root)
{
    if (root->next == NULL)
    {
        cout << root->val << " ";
        return;
    }
    display(root->next);
    cout << root->val << " ";
}
int main()
{
    node *root;
    root = enque(root, 2);
    root = enque(root, 4);
    root = enque(root,10);
   display(root);
   cout<<endl;
    root = deque(root);
    display(root);
    return 0;
}
