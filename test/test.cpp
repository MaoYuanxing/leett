// #include <iostream>
// #include <string>
// #include <vector>
// #include <cmath>
// using namespace std;

// void getScore(int format, const string &s)
// {
//     vector<int> win(10000, 0);
//     vector<int> lose(10000, 0);
//     int count = 0;
//     cout << win[2] << endl;
//     for (auto i : s)
//     {
//         if (i == 'E')
//             break;
//         if (i == 'W')
//         {
//             if ((abs(win[count] - lose[count]) >= 2) &&
//                 (win[count] >= format || lose[count] >= format))
//             {
//                 count++;
//                 win[count] += 1;
//             }
//             win[count] += 1;
//         }
//         if (i == 'L')
//         {
//             if ((abs(win[count] - lose[count]) >= 2) &&
//                 (win[count] >= format || lose[count] >= format))
//             {
//                 count += 1;
//                 lose[count] += 1;
//             }
//             lose[count] += 1;
//         }
//     }
// //     for (int i = 0; i <= count; i++)
// //     {
// //         cout << win[i] << ":" << lose[i] << endl;
// //     }
// // }

// int main()
// {
//     string item;
//     char ch;
//     while (cin >> ch && ch != 'E')
//     {
//         if (ch == 'W' || ch == 'L')
//         {
//             item += ch;
//         }
//     }
//     item += 'E';
//     cout << item.size() << endl;
//     cout << item << endl;
//     if (item == "")
//     {
//         cout << 0 << ":" << 0 << endl
//              << endl;
//         cout << 0 << ":" << 0 << endl
//              << endl;
//         return 0;
//     }
//     cout << endl;
//     getScore(11, item);
//     cout << endl;
//     getScore(21, item);

//     return 0;
// }
#include <iostream>
#include <cmath>
using namespace std;

char str[100010];
int cnt = 0;

void show(int n)
{

    int a = 0, b = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (str[i] == 'W')
            a++;
        if (str[i] == 'L')
            b++;

        if ((a >= n || b >= n) && abs(a - b) >= 2)
        {
            cout << a << ":" << b << endl;
            a = b = 0;
        }
    }

    //新的一轮刚开始，或上一局没有打完
    cout << a << ":" << b << endl;
}

int main()
{
    char ch;

    while (cin >> ch && ch != 'E')
    {
        if (ch == 'W' || ch == 'L')
        {
            str[cnt++] = ch;
        }
    }

    show(11);
    cout << endl;
    show(21);
}
