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

struct node *front = NULL;
struct node *rear = NULL;

int isEmpty(struct node *ptr)
{
    if(front == rear)
    {
        return 1;
    }
    return 0;
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

void enqueue(int data)
{
    struct node *n = new(struct node);
    if(isFull(n))
    {
        cout << "Queue is full" << endl;
    }
    else
        {
        n -> info = data;
        n -> next = NULL;
        if(front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear -> next = n;
            rear = n;
        }
    }
}

int dequeue()
{
    struct node *ptr;
    int item;
    if(isEmpty(front))
    {
        cout << "Queue is underflow." << endl;
        exit(1);
    }
    ptr = front;
    item = ptr -> info;
    front = front -> next;
    free(ptr);
    return item;
}

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

void peek(struct node *front)
{
    if(isEmpty(front))
    {
        cout << "Queue is underflow." << endl;
    }
    else
    {
        cout << "The peek element is : " << rear -> info << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display(front);
    int element = dequeue();
    display(front);
    cout << "The dequeue element from the queue is : " << endl;
    cout << element << endl;
    peek(front);
    return 0;
}