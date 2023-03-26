#ifndef _MYTREENODE_H
#define _MYTREENODE_H

struct MyTreenode
{
public:
    MyTreenode() : vaule(0), lchild(nullptr), rchild(nullptr){};
    MyTreenode(int a) : vaule(a), lchild(nullptr), rchild(nullptr){};
    int vaule;
    MyTreenode* lchild;
    MyTreenode* rchild;
};

void InOrderPrint(MyTreenode* Tree)
{
    if(Tree == nullptr)
    {
        return;
    }
    else
    {
        InOrderPrint(Tree->lchild);
        printf("%d ", Tree->vaule);
        InOrderPrint(Tree->rchild);
    }
}

void PreOrderPrint(MyTreenode* Tree)
{
    if(Tree == nullptr)
    {
        return;
    }
    else
    {
        printf("%d ", Tree->vaule);
        PreOrderPrint(Tree->lchild);
        PreOrderPrint(Tree->rchild);
    }
}

void PostOrderPrint(MyTreenode* Tree)
{
    if(Tree == nullptr)
    {
        return;
    }
    else
    {
        PostOrderPrint(Tree->lchild);
        PostOrderPrint(Tree->rchild);
        printf("%d ", Tree->vaule);
    }
}

void DeleteTree(MyTreenode* Tree)
{
    if(Tree == nullptr)
        return;
    MyTreenode* ltmp = Tree->lchild;
    MyTreenode* rtmp = Tree->rchild;
    delete Tree;
    DeleteTree(ltmp);
    DeleteTree(rtmp);
}
#endif