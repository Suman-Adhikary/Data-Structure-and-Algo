#include<iostream>
#include<stdlib.h>
using namespace std;

struct queue
{
    int front;
    int rear;
    int size;
    int *arr;
};

int isEmpty(struct queue *ptr)
{
    if(ptr -> front == ptr -> rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *ptr)
{
    if(ptr -> rear == ptr -> size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *ptr, int item)
{
    if(isFull(ptr))
    {
        cout << "Queue overflow." << endl;
    }
    if(ptr -> front == -1)
        {
            ptr -> front = 0;
        }
    ptr -> rear = ptr -> rear + 1;
    ptr -> arr[ptr -> rear] = item;
}

int dequeue(struct queue *ptr)
{
    if(isEmpty(ptr))
    {
        cout << "Queue underflow." << endl;
    }
    int item;
    ptr -> front++;
    item = ptr -> arr[ptr -> front];
    return item;
}

int peek(struct queue *ptr)
{
    if(isEmpty(ptr))
    {
        cout << "Queue is empty." << endl;
    }
    cout << "The front element of the queue is : " << ptr -> arr[ptr -> front] << endl;
    cout << "The rear element of the queue is : " << ptr -> arr[ptr -> rear] << endl;
}

void display(struct queue *ptr)
{
    if(isEmpty(ptr))
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "The Queue is : " << endl;
        for(int i = ptr -> front; i <= ptr -> rear; i++)
        {
            cout << ptr -> arr[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    struct queue *q;
    q -> front = -1;
    q -> rear = -1;
    q -> size = 20;
    q -> arr = new int[q -> size];
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    display(q);
    dequeue(q);
    display(q);
    peek(q);
    return 0;
}