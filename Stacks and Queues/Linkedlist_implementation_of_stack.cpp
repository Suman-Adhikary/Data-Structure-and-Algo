#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<array>
#include<list>
#include<map>
#include<fstream>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *top = NULL;  

void display(struct node *start)
{
    if (start == NULL)
    {
        cout << "Stack is empty.";
    }
    cout << "The elements of the stack : " << endl;
    while(start != NULL)
    {
        cout << start -> info << endl;
        start = start -> next;
    }
}

int isEmpty(struct node *ptr)
{
    if(ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct node *ptr)
{
    struct node *p = new(struct node);
    if(p == NULL)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

struct node *push(struct node *ptr, int item)
{
    if(isFull(ptr))
    {
        cout << "Stack overflow." << endl;
    }
    else
    {
        struct node *p = new(struct node);
        p -> info = item;
        p -> next = ptr;
        ptr = p;
        return ptr;
    }
}

int pop(struct node *ptr)
{
    if(isEmpty(ptr))
    {
        cout << "Stack underflow." << endl;
    }
    else
    {
        struct node *p = ptr;
        top = ptr -> next;
        int x = p -> info;
        free(p);
        return x;
    }
}

int peek(struct node *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is empty." << endl;
        exit(1);
    }
    else
    {
        cout << "The peek element is : " << ptr -> info;
    }
}

int main()
{
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    display(top);
    int element = pop(top);
    cout << "The poped element is : " << element << endl;
    display(top);
    peek(top);
    return 0;
}