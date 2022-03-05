#include <iostream>
using namespace std;
class LinkedNode
{
public:
    LinkedNode() : val(0), next(nullptr) {}
    LinkedNode(int val, LinkedNode *next = 0) : val(val), next(next) {}
    int val;
    LinkedNode *next;
};

class DLLNode
{
public:
    DLLNode(int val = 0, DLLNode *pre = 0, DLLNode *next = 0) : val(val), pre(pre), next(next){};

    int val;
    DLLNode *pre;
    DLLNode *next;
};

LinkedNode *reverseList(LinkedNode *head)
{
    if (head->next == 0)
        return head;
    LinkedNode *pre = 0;
    LinkedNode *cur = head;
    while (cur)
    {
        LinkedNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

void printList(LinkedNode *head)
{
    LinkedNode *p;
    for (p = head; p; p = p->next)
    {
        cout << p->val << ", ";
    }
    cout << endl;
}

class MyQueue
{
    LinkedNode *head;
    LinkedNode *tail;
    int __size;

public:
    MyQueue() : head(0), tail(0), __size(0) {}
    bool isEmpty()
    {
        return __size == 0;
    }
    int size()
    {
        return __size;
    }
    void push(int el)
    {
        LinkedNode *p = new LinkedNode(el);
        if (head == 0)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            tail = tail->next;
        }
        __size++;
    }
    int pop()
    {

        int ans = -1;
        if (head)
        {
            LinkedNode *p = head;
            ans = head->val;
            head = head->next;
            delete p;
            __size--;
        }
        if (head == 0)
        {
            tail = 0;
        }

        return ans;
    }
    int peek()
    {
        int ans = -1;
        if (head)
            ans = head->val;
        return ans;
    }
};

class MyStack
{
    LinkedNode *head;
    int __size;

public:
    MyStack() : head(0), __size(0) {}
    bool isEmpty()
    {
        return __size == 0;
    }
    int size()
    {
        return __size;
    }
    void push(int el)
    {
        head = new LinkedNode(el, head);
        __size++;
    }
    void pop()
    {
        if (head)
        {
            LinkedNode *p = head;
            head = head->next;
            __size--;
            delete p;
        }
    }
    int peek()
    {
        return head ? head->val : -1;
    }
};

class MyDeque
{
    int size;
    DLLNode *head;
    DLLNode *tail;

public:
    MyDeque() : size(0), head(0), tail(0) {}
    bool isEmpty()
    {
        return size == 0;
    }
    int length()
    {
        return size;
    }
    void push_front(int val)
    {
        DLLNode *p = new DLLNode(val);
        if (head == 0)
        {
            head = p;
            tail = p;
        }
        else
        {
            p->next = head;
            head->pre = p;
            head = p;
        }
        size++;
    }
    void push_back(int val)
    {
        DLLNode *p = new DLLNode(val);
        if (tail == 0)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            p->pre = tail;
            tail = p;
        }
        size++;
    }
    int pop_front()
    {
        int ans = -1;
        if (head)
        {
            DLLNode *p = head;
            ans = head->val;
            if (head == tail)
            {
                head = tail = 0;
            }
            else
            {
                head = head->next;
                head->pre = 0;
            }
            delete p;
        }
        return ans;
    }
    int pop_back()
    {
        int ans = -1;
        if (tail)
        {
            DLLNode *p = tail;
            ans = tail->val;
            if (head == tail)
            {
                head = tail = 0;
            }
            else
            {
                tail = tail->pre;
                tail->next = 0;
            }
            delete p;
        }
        return ans;
    }
};

int main()
{
    // MyQueue A;
    // int n = 9;
    // for (int i = 0; i < 9; i++)
    // {
    //     A.push(i);
    // }
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << A.peek() << ", " << A.size() << "--";
    //     A.pop();
    // }
    // cout << endl;

    MyDeque A;
    A.push_back(0);
    A.push_front(1);
    A.push_front(2);
    A.push_back(-1);
    for (int i = 0; i < 2; i++)
        cout << A.pop_back() << ", ";
    cout << endl;
    for (int i = 0; i < 2; i++)
        cout << A.pop_front() << ", ";
    return 0;
}