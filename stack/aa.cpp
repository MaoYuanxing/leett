#include <iostream>
#include <vector>
#include <bitset>
#include <list>
using namespace std;

class Animal
{
public:
    virtual void action() = 0;
};
class Cow : public Animal
{
public:
    virtual void action()
    {
        cout << "I am Cow..." << endl;
    }
};
class Tiger : public Cow
{
public:
    virtual void action()
    {
        cout << "I am Tiger..." << endl;
    }
};

void print() { cout << endl; }
template <class T, typename... Type>
void print(const T &firstarg, const Type &...args)
{
    cout << firstarg << ", ";
    print(args...);
}
template <typename... Type>
void print(const Type &...args)
{
    cout << "this is 0+x...";
}
void print(initializer_list<int> vals)
{
    cout << "using initializer_list..." << endl;
    for (auto p = vals.begin(); p != vals.end(); ++p)
    {
        cout << *p << ", ";
    }
    cout << endl;
}
int Find(int x, int a[])
{
    if (a[x] <= 0)
        return x;
    else
        return a[x] = Find(a[x], a);
}
int main()
{
    // vector<Animal *> arr;
    // Tiger tiger;
    // Cow cow;
    // arr.push_back(&tiger);
    // arr.push_back(&cow);
    // for (auto animal : arr)
    // {
    //     animal->action();
    // }
    // print(7, 'c', "I am testing...", bitset<16>(3453), 57.2532);
    // print({12, 2, 3, 4, 5, 11, 13, 14, 17, 90});

    // int id = 0;
    // auto f = [id]() // mutable
    // {
    //     cout << "id= " << id << endl;
    //     ++id;
    // };
    // id = 42;
    // f();
    // f();
    // f();
    // cout << "id= " << id << endl;

    // int a[5] = {-1, 0, 1, 2, 3};
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << i << ": " << a[i] << ",";
    // }
    // cout << endl;
    // Find(4, a);

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << i << ": " << a[i] << ",";
    // }
    // cout << endl;

    // list<int> b;
    // cout << b.max_size();

    // int a[9] = {0, 1, 1, 2, 3, 4, 5, 6, 7};
    // cout << "[";
    // // 1
    // for (int i : a)
    // {
    //     cout << i << ", ";
    // }
    // cout << "]" << endl;
    // int p = 8;
    // while (p != a[p])
    // {
    //     a[p] = a[a[p]];
    //     p = a[p];
    // }
    // // 2
    // cout << "[";
    // for (int i : a)
    // {
    //     cout << i << ", ";
    // }
    // cout << "]" << endl;
    // p = 8;
    // while (p != a[p])
    // {
    //     a[p] = a[a[p]];
    //     p = a[p];
    // }
    // // 3
    // cout << "[";
    // for (int i : a)
    // {
    //     cout << i << ", ";
    // }
    // cout << "]" << endl;
    // p = 8;
    // while (p != a[p])
    // {
    //     a[p] = a[a[p]];
    //     p = a[p];
    // }
    // // 3
    // cout << "[";
    // for (int i : a)
    // {
    //     cout << i << ", ";
    // }
    // cout << "]" << endl;

    int a[5] = {1, 2, 3, 4, 5};
    cout << *(*(&a + 1) - 1);
    return 0;
}