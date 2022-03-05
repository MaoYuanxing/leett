#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <memory>
using namespace std;

void f(int i, int j)
{
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
}

int g(int i)
{
    cout << "G():" << endl;
    return i;
}
int h(int j)
{
    cout << "H():" << endl;
    return j * j;
}
void ff(int *q)
{
    *q += 10;
}
void ff(int &a)
{
    a += 10;
}

int main()
{
    // int n, m;
    // cin >> n >> m;
    // vector<vector<int>> ans(n, vector<int>(m));

    // int count = 0;
    // char ch;
    // for (int i = 0; i < n; i++) //读入地图
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin >> ch; //读入每一个点
    //         if (ch == '*')
    //             ans[i][j] = -1; //如果是地雷就将这个点设为一
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (ans[i][j] == -1)
    //             continue;
    //         if (i - 1 >= 0 && ans[i - 1][j] == -1)
    //             ans[i][j]++;
    //         if (i + 1 < n && ans[i + 1][j] == -1)
    //             ans[i][j]++;
    //         if (j - 1 >= 0 && ans[i][j - 1] == -1)
    //             ans[i][j]++;
    //         if (j + 1 < m && ans[i][j + 1] == -1)
    //             ans[i][j]++;
    //         if (i - 1 >= 0 && j - 1 >= 0 && ans[i - 1][j - 1] == -1)
    //             ans[i][j]++;
    //         if (i - 1 >= 0 && j + 1 < m && ans[i - 1][j + 1] == -1)
    //             ans[i][j]++;
    //         if (i + 1 < n && j + 1 < m && ans[i + 1][j + 1] == -1)
    //             ans[i][j]++;
    //         if (i + 1 < n && j - 1 >= 0 && ans[i + 1][j - 1] == -1)
    //             ans[i][j]++;
    //     }
    // }
    // cout << endl;
    // for (auto c : ans)
    // {
    //     for (int i : c)
    //     {
    //         if (i == -1)
    //             cout << '*';
    //         else
    //             cout << i;
    //     }
    //     cout << endl;
    // }

    // cout << INT32_MAX << endl;
    // f(2, 2);
    // f(g(2), h(2));
    int *i = new int;
    auto_ptr<int> x(i);
    auto_ptr<int> y;

    y = x;

    cout << x.get() << endl; // Print NULL
    cout << y.get() << endl; // Print non-NULL address i
    cout << i << endl;
    return 0;
}