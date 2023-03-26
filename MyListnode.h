#ifndef _MYLISTNODE_H
#define _MYLISTNODE_H

struct MyListnode
{
public:
    MyListnode();
    MyListnode(int a);
    int value;
    MyListnode* next;
};

MyListnode::MyListnode()
{
    value = 0;
    next = nullptr;
}

MyListnode::MyListnode(int a)
{
    value = a;
    next = nullptr;
}
#endif