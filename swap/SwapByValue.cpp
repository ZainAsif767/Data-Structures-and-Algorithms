#include <iostream>
using namespace std;
// called by value
void swap(int a, int b)
{
    int c;
    c = a;
    a = b;
    b = c;
    printf("a=%d, b=%d ", a, b);
}
int main()
{
    int x = 5;
    int y = 6;
    swap(x, y);
    printf("x =%d, y =%d ", x, y);
    return 0;
}
// x , y wont swap they will remain intact
