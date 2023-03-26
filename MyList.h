#ifndef _MYLIST_H
#define _MYLIST_H

#include <vector>
#include "MyListnode.h"

struct MyList
{
public:
    MyList();
    MyList(std::vector<int> &vec);
    MyList(MyList &list);
    MyList& operator=(MyList &rhs);
    ~MyList();
    void Print();
    int PushBack(MyListnode &node);
    int Insert(MyListnode &node, int pos);
    int Delete(int pos);
private:
    MyListnode* Head;
    MyListnode* Tail;
};

MyList::MyList()
{
    Head = nullptr;
    Tail = nullptr;
}

MyList::MyList(std::vector<int> &vec)
{
    Head = new MyListnode(vec.size());
    MyListnode* tmp = Head;
    for(auto i : vec)
    {
        tmp->next = new MyListnode(i);
        tmp = tmp->next;
    }
    Tail = new MyListnode(-999);
    tmp->next = Tail;
}

MyList::MyList(MyList &list)
{
    Head = new MyListnode(list.Head->value);
    MyListnode* tmp = Head;
    MyListnode* listtmp = list.Head->next;
    while(listtmp)
    {
        tmp->next = new MyListnode(listtmp->value);
        tmp = tmp->next;
        listtmp = listtmp->next;
    }
    Tail = tmp;
}

MyList& MyList::operator=(MyList &rhs)
{
    if(Head == rhs.Head)
    {
        return *this;
    }
    MyListnode* tmp = Head;
    while(Head)
    {
        Head = Head->next;
        delete tmp;
        tmp = Head;
    }
    Head = new MyListnode(rhs.Head->value);
    tmp = Head;
    MyListnode* rhstmp = rhs.Head->next;
    while(rhstmp)
    {
        tmp->next = new MyListnode(rhstmp->value);
        tmp = tmp->next;
        rhstmp = rhstmp->next;
    }
    Tail = tmp;
    return *this;
}

MyList::~MyList()
{
    MyListnode* tmp = Head;
    while(Head)
    {
        Head = Head->next;
        delete tmp;
        tmp = Head;
    }
}

void MyList::Print()
{
    MyListnode* tmp = Head->next;
    printf("begin&len : [%x : %d] \n", &(Head->value), Head->value);
    for(int i = 0; i < Head->value; ++i)
    {
        printf("[%x : %d] ", &(tmp->value), tmp->value);
        tmp = tmp->next;
    }
    printf("\nend : [%x : %d]\n", &(tmp->value), tmp->value);
}

int MyList::PushBack(MyListnode &node)
{
    Tail->value = node.value;
    Tail->next = new MyListnode(-999);
    ++Head->value;
    return 0;
}

int MyList::Insert(MyListnode &node, int pos)
{
    if(pos > Head->value)
    {
        printf("Overrange!!");
        return -1;
    }
    MyListnode* tmp = Head;
    MyListnode* tmpnext = tmp->next;
    for(int i =0; i < pos-1; ++i)
    {
        tmp = tmp->next;
        tmpnext = tmpnext->next;
    }
    tmp->next = new MyListnode(node.value);
    tmp = tmp->next;
    tmp->next = tmpnext;
    ++Head->value;
    return 0;
}

int MyList::Delete(int pos)
{
    if(pos > Head->value)
    {
        printf("Overrange!!");
        return -1;
    }
    MyListnode* tmp = Head;
    MyListnode* tmpnext = tmp->next;
    for(int i =0; i < pos-1; ++i)
    {
        tmp = tmp->next;
        tmpnext = tmpnext->next;
    }
    tmp->next = tmpnext->next;
    delete tmpnext;
    --Head->value;
    return 0;    
}
#endif