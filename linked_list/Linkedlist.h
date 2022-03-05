#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

class LinkedNode
{
public:
    LinkedNode() : val(0), next(nullptr) {}
    LinkedNode(int val, LinkedNode *next = 0) : val(val), next(next) {}
    int val;
    LinkedNode *next;
};

class Linkedlist
{
    LinkedNode *head;
    LinkedNode *tail;

public:
    Linkedlist() : head(0), tail(0) {}
    ~Linkedlist() {}
    bool isEmpty()
    {
        return head == 0;
    }
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead(); // delete head return its val
    int deleteFromTail(); // delete tail return its val
    void deleteNode(int);
    bool isInList(int);
};

#endif