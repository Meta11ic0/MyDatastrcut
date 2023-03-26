#ifndef _MYSTACK_H
#define _MYSTACK_H

#include <vector>
struct MyStack
{
public:
    MyStack():Top(-1){};
    int Pop();
    int Push(int i);
    int Top;
private:
    int Data[10] = {0};
};

int MyStack::Pop()
{
    if(Top == -1)
    {
        printf("Stack is empty!\n");
        return 0;
    }
    else
    {
        return Data[Top--];
    }
}

int MyStack::Push(int i)
{
    if(Top == 9)
    {
        printf("MyStack is full!\n");
        return -1;
    }
    else
    {
        Data[++Top] = i;
        return Data[Top];
    }

}

#endif
