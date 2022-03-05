#include <iostream>
#include "Linkedlist.h"
using namespace std;

Linkedlist::~Linkedlist()
{
    for (LinkedNode *p; !isEmpty();)
    {
        p = head->next;
        delete head;
        head = p;
    }
}

void Linkedlist::addToHead(int val)
{
    head = new LinkedNode(val, head);
    if (tail == 0)
        tail = head;
}

void Linkedlist::addToTail(int val)
{
    if (tail != 0)
    {
        tail->next = new LinkedNode(val);
        tail = tail->next;
    }
    else
        head = tail = new Linkedlist(val);
}

int Linkedlist::deleteFromHead()
{
    int ans = head->val;
    LinkedNode *p = head;
    if (head == tail)
        head = tail = 0;
    else
        head = head->next;
    delete p;
    return ans;
}
int Linkedlist::deleteFromTail()
{
    int ans = tail->val;
    LinkedNode *p = tail;
    if (head == tail)
        head = tail = 0;
    else
    {
        for (LinkedNode *q = head; q->next != tail; q = q->next)
            ;
        tail = q;
        tail->next = 0;
        s
    }
    delete p;
    return ans;
}

void Linkedlist::deleteNode(int val)
{
    if (head != 0)
    {
        if (head == tail && val == head->val)
        {
            delete head;
            head = tail = 0;
        }
        else if (val == head->val)
        {
            LinkedNode *p = head;
            head = head->next;
            delete p;
        }
        else
        {
            for (LinkedNode *p = head->next,
                            *pre = head;
                 p->val != val && p;
                 p = p->next, pre = pre->next)
                ;
            if (p != 0)
            {
                pre->next = p->next;
                if (p == tail)
                    tail = pre;
                delete p;
            }
        }
    }
}

bool Linkedlist::isInList(int val) const
{
    LinkedNode *p;
    for (p = head; p && p->val != val; p = p->next)
        ;
    return p != 0;
}