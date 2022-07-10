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
    if(ptr -> front == -1)
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
    if(ptr -> front == ptr -> rear + 1)
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
        return;
    }
    if(ptr -> front == -1)
        {
            ptr -> front = 0;
        }
    if(ptr -> rear == ptr -> size - 1)
    {
        ptr -> rear = 0;
    }
    else
    {
        ptr -> rear = ptr -> rear + 1;
    }
    ptr -> arr[ptr -> rear] = item;
}

void dequeue(struct queue *ptr)
{
    int item;
    if(isEmpty(ptr))
    {
        cout << "Queue underflow." << endl;
    }
    item = ptr -> arr[ptr -> front];
    if(ptr -> front == ptr -> rear)
    {
        ptr -> front = -1;
        ptr -> rear = -1;
    }
    else if(ptr -> front == ptr -> size - 1)
    {
        ptr -> front = 0;
    }
    else
    {
        ptr -> front = ptr -> front + 1;
    }
    cout << "The dequeue element from queue is : " << item << endl;
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
    enqueue(q, 10);
    display(q);
    peek(q);
    return 0;
}