#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class graph
{
public:
    string E, V;
    int **arr;
    graph(string filename)
    {
        ifstream file(filename);
        string str;
        int flag = 1;
        while (getline(file, str))
        {
            if (flag == 1)
            {
                V = str;
                initializing_array(stoi(V));
            }
            if (flag == 2)
            {
                E = str;
            }
            if (flag >= 3)
            {
                int r, c;
                for (int j = 0; j < str.length(); j++)
                {
                    if (str[j] == ',')
                    {
                        r = stoi(str.substr(0, j));
                        c = stoi(str.substr(j + 1, str.length() - (j + 1)));
                        break;
                    }
                }
                arr[r][c] = 1;
            }
            flag += 1;
        }
    }
    void initializing_array(int V)
    {
        arr = new int *[V];
        for (int i = 0; i < V; i++)
        {
            arr[i] = new int[V];
        }

        for (int i = 0; i < V; i++)
        {
            for (int k = 0; k < V; k++)
            {
                arr[i][k] = 0;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < stoi(V); i++)
        {
            for (int j = 0; j < stoi(V); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~graph()
    {
        for (int i = 0; i < stoi(V); i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
int main()
{
    graph g1("values.txt");
    g1.display();
}
