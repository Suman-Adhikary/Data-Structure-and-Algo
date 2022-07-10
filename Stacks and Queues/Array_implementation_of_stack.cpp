#include <iostream>
#include <stdlib.h>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int item)
{
    if (isFull(ptr))
    {
        cout << "Stack overflow." << endl;
    }
    ptr->top++;
    ptr->arr[ptr->top] = item;
}

int pop(struct stack *ptr)
{
    int item;
    if (isEmpty(ptr))
    {
        cout << "Stack is Underflow" << endl;
    }
    else
    {
        item = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
    }
    return item;
}

void peek(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        cout << "Stack is underflow." << endl;
        exit(1);
    }
    else
    {
        cout << "The top element of the stack is : ";
        cout << ptr -> arr[ptr -> top] << endl;
    }
}

void display(struct stack *ptr)
{
    int i;
    if (isEmpty(ptr))
    {
        cout << "Stack is Empty." << endl;
    }
    else
    {
        cout << "Stack elements are : " << endl;
        for (i = ptr->top; i >= 0; i--)
        {
            cout << ptr->arr[i] << endl;
        }
    }
}

int main()
{
    struct stack *s;
    s->size = 20;
    s->top = -1;
    s->arr = new int[s->size];
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    // pop(s);
    display(s);
    peek(s);
    return 0;
}