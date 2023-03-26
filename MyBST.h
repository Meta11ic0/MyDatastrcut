#ifndef _MYSBT_H
#define _MYSBT_H

#include <vector>
#include "MyTreenode.h"

struct MyBST : public MyTreenode
{
public:
    MyBST():Root(nullptr){};
    MyBST(std::vector<int> &vec);
    ~MyBST();
    void Insert(MyTreenode* &Root, int i);
    MyTreenode* Root;
};

MyBST::MyBST(std::vector<int> &vec)
{
    for(int i : vec)
    {
        Insert(Root, i);
    }
}

void MyBST::Insert(MyTreenode* &Root, int i)
{
    if(Root == nullptr)
        Root = new MyTreenode(i);
    else
    {
        if(Root->vaule > i)
        {
            if(Root->lchild == nullptr)
            {
                Root->lchild = new MyTreenode(i);
            }
            else
            {
                Insert(Root->lchild, i);
            }
            
        }
        else
        {
           if(Root->rchild == nullptr)
            {
                Root->rchild = new MyTreenode(i);
            }
            else
            {
                Insert(Root->rchild, i);
            }
        }
    }
}

MyBST::~MyBST()
{
    DeleteTree(Root);
}
#endif