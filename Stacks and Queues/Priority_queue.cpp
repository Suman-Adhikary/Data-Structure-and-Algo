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
    int priority;
    int info;
    struct node *next;
};
struct node *front = NULL;

int isEmpty()
{
    if(front == NULL)
    {
        return 1;
    }
    return 0;
}

void insert(int item, int item_priority)
{
    struct node *temp, *p;
    temp = new(struct node);
    if(temp == NULL)
    {
        cout << "Memory not available." << endl;
        return;
    }
    temp -> info = item;
    if(isEmpty() || item_priority < front -> priority)
    {
        temp -> next = front;
        front = temp;
    }
    else
    {
        while(p -> next != NULL && p -> next -> priority <= item_priority)
        {
            p = p -> next;
        }
        temp -> next = p -> next;
        p -> next = temp;
    }
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

int main()
{
    insert(20, 1);
    insert(10, 1);
    display(front);
    return 0;
}