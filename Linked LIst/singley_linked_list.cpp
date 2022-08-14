#include<iostream>
using namespace std;

class Node
{
    public:
        int info;
        Node *link;
};

void Traversal(Node *start)
{
    Node *p = start;
    while(p != NULL)
    {
        cout << p -> info << " "; 
        p = p -> link;
    }
    cout << endl;
}

Node *InsertAtFirst(Node *start, int data)
{
    Node *temp = new(Node);
    temp -> info = data;
    temp -> link = start;
    start = temp;
    return start;
}

Node *InsertAtLast(Node *start, int data)
{
    Node *p;
    Node *temp = new(Node);
    temp -> info = data;
    p = start;
    while(p -> link != NULL)
    {
        p = p -> link;
    }
    p -> link = temp;
    temp -> link = NULL;
    return start;
}

Node *InsertAtBetBef(Node *start, int data, int item)
{
    Node *temp, *p;
    if(start == NULL)
    {
        cout << "The list is empty." << endl;
    }
    if(item == start -> info)
    {
        temp = new(Node);
        temp -> info = data;
        temp -> link = start;
        start = temp;
        return start;
    }
    p = start;
    while(p != NULL)
    {
        if(p -> link -> info == item)
        {
            temp = new(Node);
            temp -> info = data;
            temp -> link = p -> link;
            p -> link = temp;
            return start;
        }
        p = p -> link;
    }
}

Node *InsertAtBetAft(Node *start, int data, int item)
{
    Node *temp, *p;
    p = start;
    while(p != NULL)
    {
        if(p -> info == item)
        {
            temp = new(Node);
            temp -> info = data;
            temp -> link = p -> link;
            p -> link = temp;
            return start;
        }
        p = p -> link;
    }
}

Node *InsertAtPos(Node *start, int data, int pos)
{
    Node *temp, *p;
    temp = new(Node);
    temp -> info =  data;
    if(pos == 1)
    {
        temp -> link = start;
        start = temp;
        return start;
    }
    p = start;
    for(int i = 1; i < pos-1 && p != NULL; i++)
    {
        p = p -> link;
    }
    if(p == NULL)
    {
        cout << "The are less than " << pos  << " element." << endl;
    }
    else
    {
        temp -> link = p -> link;
        p -> link = temp;
    }
    return start;
}

Node *CreateList(Node *start)
{
    int n, item;
    start = NULL;
    cout << "Enter the size of list : " << endl;
    cin >> n;
    if(n == 0)
    {
        cout << "You enter the 0 size of a list." << endl;
        return start;    
    }
    else
    {
        cout << "Enter the first element : " << endl;
        cin >> item;
        start = InsertAtFirst(start, item);
        cout << "Enter the other element : " << endl;
        for(int i = 2; i <= n; i++)
        {
            cin >> item;
            start = InsertAtLast(start, item);
        }
        cout << "The linked list is : " << endl;
        return start;
    }
}

Node *Deletation(Node *start, int item)
{
    Node *temp, *p;
    if(start -> info == item)
    {
        temp = start;
        start = start -> link;
        free(temp);
        return start;
    }
    p = start;
    while(p != NULL)
    {
        if(p -> link -> info == item)
        {
            temp = p -> link;
            p -> link = temp -> link;
            free(temp);
            return start;
        }
        p = p -> link;
    }
}

Node *DeleteInPos(Node *start, int pos)
{
    Node *temp, *p;
    if(pos == 1)        // For first position.
    {
        temp = start;
        start = start -> link;
        free(temp);
        return start;
    }
    int count = 2;      // For other position.
    p = start;
    while(count < pos)
    {
        p = p -> link;
        count++;
    }
    temp = p -> link;
    p -> link = temp -> link;
    free(temp);
    return start;
}

Node *Reverse(Node *start)
{
    Node *prev, *ptr, *next;
    prev = NULL;
    ptr = start;
    while(ptr != NULL)
    {
        next = ptr -> link;
        ptr -> link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    cout << "The reverse list is : " << endl;
    return start;
}

int main()
{
    Node *head = new(Node);
    // Node *first = new(Node);
    // Node *second = new(Node);
    // head -> info = 10;
    // head -> link = first;
    // first -> info = 20;
    // first -> link = second;
    // second -> info = 30;
    // second -> link = NULL;
    // Traversal(head);
    // head = InsertAtFirst(head, 0);
    // Traversal(head);
    // head = InsertAtLast(head, 40);
    // Traversal(head);
    // head = InsertAtBetBef(head, 35, 40);
    // Traversal(head);
    // head = InsertAtBetAft(head, 25, 20);
    // Traversal(head);
    // head = InsertAtPos(head, 15, 3);
    // Traversal(head);
    head = CreateList(head);
    Traversal(head);
    // head = Deletation(head, 10);
    // Traversal(head);
    head = DeleteInPos(head, 2);
    Traversal(head);
    // head = Reverse(head);
    // Traversal(head);
    return 0;
}