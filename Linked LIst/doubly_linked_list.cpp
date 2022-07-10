#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<array>
using namespace std;

struct node 
{
    struct node *prev;
    int info;
    struct node *next;
};

void Traversal(struct node *start)
{
    struct node *p;
    if(start == NULL)
    {
        cout << "The list is empty." << endl;
    }
    p = start;
    while(p != NULL )
    {
        cout << p -> info << " ";
        p = p -> next;
    }
    cout << endl;
}

void searchingAnElement(struct node *start, int data)
{
    struct node *p;
    int pos = 1;
    p = start;
    while(p != NULL)
    {
        if(p -> info == data)
        {
            cout << "The " << data << " found at possition " << pos << '.' << endl;
        }
        p = p -> next;
        pos++;
    }
}

struct node *insertAtEmp(struct node *start, int data)
{
    struct node *temp;
    temp = new(struct node);
    temp -> info = data;
    temp -> next = NULL;
    temp -> prev = NULL;
    start = temp;
    return start;
}

struct node *insertAtFirst(struct node *start, int data)
{
    struct node *temp;
    temp = new(struct node);
    temp -> info = data;
    temp -> prev = NULL;
    temp -> next = start;
    start -> prev = temp;
    start = temp;
    return start;
}

struct node *insertAtLast(struct node *start, int data)
{
    struct node *temp, *p;
    temp = new(struct node);
    temp -> info = data;
    p = start;
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = temp;
    temp -> prev = p;
    temp -> next = NULL;
    return start;
}

struct node *insertAtBetAft(struct node *start, int data, int item)
{
    struct node *temp, *p;
    temp = new(struct node);
    p = start;
    while(p != NULL)
    {
        if(p -> info == item)
        {
            temp -> info = data;
            temp -> prev = p;
            temp -> next = p -> next;
            if(p -> next != NULL)
            {
                p -> next -> prev = temp;
            }
            p -> next = temp;
            return start;
        }
        p = p -> next;
    }
    cout << "The " << item << " not present in the list." << endl;
    return start;
}

struct node *insertAtBetBef(struct node *start, int data, int item)
{
    struct node *temp, *q;
    temp = new(struct node);
    if(start == NULL)
    {
        cout << "This is an empty list." << endl;
        return start;
    }
    if(start -> info == item)
    {
        temp -> info = data;
        temp -> prev = NULL;
        temp -> next = start;
        start -> prev = temp;
        start = temp;
        return start;
    }
    q = start;
    while(q != NULL)
    {
        if(q -> info == item)
        {
            temp -> info = data;
            temp -> prev = q -> prev;
            temp -> next = q;
            temp -> prev -> next = temp;
            q -> prev = temp;
            return start;
        }
        q = q -> next;
    }
    cout << "The " << item << " not present in the list." << endl;
    return start;
}

struct node *create_list(struct node *start)
{
    int n, p;
    cout << "Enter how many number do you want to add?" << endl;
    cin >> n;
    start = NULL;
    if(n == 0)
    {
        cout << "You don't add any elemnt." << endl;
        return start;
    }
    cout << "Enter the first element : ";
    cin >> p;
    start = insertAtEmp(start, p);
    cout << "Enter the other elemnt : ";
    for(int i = 2; i <= n; i++)
    {
        cin >> p;
        start = insertAtLast(start, p);
    }
    cout << "The created doubly linked list : " <<  endl;
    return start;
}

struct node *insertAtBetPos(struct node *start, int data, int pos)
{
    struct node *temp, *p;
    p = start;
    temp = new(struct node);
    temp -> info = data;
    for(int i = 1; i < pos - 1; i++)
    {
        p = p -> next;
    }
    if(p == NULL)
    {
        cout << "There are less than " << pos << " elements." << endl; 
    }
    else
    {
        temp -> next = p -> next;
        temp -> prev = p;
        p -> next = temp;
    }
    return start;
}

struct node *del(struct node *start, int item)
{
    struct node *temp;
    if(start == NULL)
    {
        cout << "This is an empty list." << endl;
    }
    if(start -> next == NULL) // Deletation of only node.
    {
        if(start -> info == item)
        {
            temp = start;
            start = NULL;
            free(temp);
            return start;
        }
        else
        {
            cout << "Element " << item << " not in the list." << endl;
            return start;
        }
    }
    if(start -> info == item) // Deletation of the first node.
    {
        temp = start;
        start = start -> next;
        start -> prev = NULL;
        free(temp);
        return start;
    }
    temp = start -> next; // Deletation node in between.
    while(temp -> next != NULL) 
    {
        if(temp -> info == item) 
        {
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            free(temp);
            return start;
        }
        temp = temp -> next;
    }    
    if (start -> info == item) // Deletation node at the end.
    {
        temp -> prev -> next = NULL;
        free(temp);
        return start;
    }
    cout << "Element " << item << " not found in the list." << endl;
    return start; 
}

struct node *reverse(struct node *start)
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1 -> next;
    p1 -> next = NULL;
    p1 -> prev = p2;
    while(p2 != NULL)
    {
        p2 -> prev = p2 -> next;
        p2 -> next = p1;
        p1 = p2;
        p2 = p2 -> prev;
    }
    start = p1;
    return start;
}

int main()
{
    struct node *head, *first, *second;
    head = new(struct node);
    first = new(struct node);
    second = new(struct node);

    head -> prev = NULL;
    head -> info = 10;
    head -> next = first;
    first -> prev = head;
    first -> info = 20;
    first -> next = second;
    second -> prev = first;
    second -> info = 30;
    second -> next = NULL;
    
    cout << "Displaying the doubly linked list : " << endl;
    Traversal(head);
    cout << "Searching an element in a doubly linked list : " << endl;
    searchingAnElement(head, 10);
    cout << "Insert element at first in the list : " << endl;
    head = insertAtFirst(head, 0);
    Traversal(head);
    cout << "Insert element at last in the list : " << endl;
    head = insertAtLast(head, 40);
    Traversal(head);
    cout << "Insert an element between the list after an element." << endl;
    head = insertAtBetAft(head, 25, 20);
    Traversal(head);
    cout << "Insert an element between the list before an element." << endl;
    head = insertAtBetBef(head, 35, 40);
    Traversal(head);
    cout << "Insert an element between the list in user defined possition." << endl;
    head = insertAtBetPos(head, 15, 3);
    Traversal(head);
    // cout << "Creating doubly linked list : " << endl;
    // head = create_list(head);
    // Traversal(head);
    // cout << "Deletation of a node : " << endl;
    // head = del(head, 35);
    // Traversal(head);
    cout << "The reverse of a doubly linked list : " << endl;
    head = reverse(head);
    Traversal(head);

    return 0;
}