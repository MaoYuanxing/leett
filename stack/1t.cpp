#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Component
{
public:
    Component()
    {
        cout << "Component ctor" << endl;
    }
};
class Base
{
private:
    Component com;

public:
    Base()
    {
        cout << "Base ctor" << endl;
    }
};

class Derived : public Base
{

public:
    Derived()
    {
        cout << "Derived ctor" << endl;
    }
};

int largestRectangleArea(vector<int> &heights)
{
    stack<int> s1, s2;
    vector<int> v1, v2;
    int n = heights.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1.empty())
        {
            s1.push(i);
            v1.push_back(-1);
        }
        else if (heights[s1.top()] < heights[i])
        {
            v1.push_back(s1.top());
            s1.push(i);
        }
        else
        {
            while (!s1.empty() && heights[s1.top()] >= heights[i])
            {
                s1.pop();
            }
            if (s1.empty())
                v1.push_back(-1);
            else
                v1.push_back(s1.top());
            s1.push(i);
        }
        if (s2.empty())
        {
            s2.push(n - i - 1);
            v2.push_back(n);
        }
        else if (heights[s2.top()] < heights[n - i - 1])
        {
            v2.push_back(s2.top());
            s2.push(n - i - 1);
        }
        else
        {
            while (!s2.empty() && heights[s2.top()] >= heights[n - 1 - i])
            {
                s2.pop();
            }
            if (s2.empty())
                v2.push_back(n);
            else
                v2.push_back(s2.top());
            s2.push(n - 1 - i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << v2[n - 1 - i] << ", ";

        ans = max(ans, (v2[n - i - 1] - v1[i] - 1) * heights[i]);
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << v1[i] << ", ";
    return ans;
}
string decodeString(string s)
{
    stack<int> st;
    vector<string> aux(3);
    int count = 0;
    int num = 0;
    for (char c : s)
    {

        if (c != '[')
        {
            if (c <= '9' && c >= '0')
            {
                num = (num * 10 + (c - '0'));
                cout << num << endl;
            }
            else if (c <= 'z' && c >= 'a')
            {
                if (st.empty())
                    aux[0].push_back(c);
                if (!st.empty())
                    aux[count].push_back(c);
            }
            else if (c == ']')
            {

                if (st.empty())
                    continue;
                for (int i = 0; i < st.top(); i++)
                {
                    aux[count - 1] += aux[count];
                }
                st.pop();
                count--;
            }
        }
        if (c == '[')
        {
            cout << num << endl;
            st.push(num);
            num = 0;
            count++;
            cout << count << ", ";
        }
    }
    return "test";
}
int main()
{

    cout << __cplusplus << endl;
    return 0;
}