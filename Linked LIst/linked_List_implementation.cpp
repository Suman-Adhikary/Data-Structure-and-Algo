#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void LinkedlistTraversal(struct node *ptr)
{
    while(ptr != NULL)
        {
            cout << "Element : " << ptr -> data << endl;
            ptr = ptr -> next; 
        }
}

int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;

    head = new(struct node);
    first = new(struct node);
    second = new(struct node);
    third = new(struct node);

    head -> data = 0;
    head -> next = first;
    first -> data = 10;
    first -> next = second;
    second -> data = 20;
    second -> next = third;
    third -> data = 30;
    third -> next = NULL;

    LinkedlistTraversal(head);

    return 0;
}