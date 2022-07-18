// Q.1) Write a function to count the number of occurrences of an element in a singly linked list.
// Q.2) Write a function to find the maximum and minimum value from a singly linked list.

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct node *insertAtFirst(struct node *start, int item)
{
    struct node *ptr = new (struct node);
    ptr->data = item;
    ptr->next = start;
    return ptr;
}

struct node *insertAtLast(struct node *start, int item)
{
    struct node *ptr, *p;
    ptr = new (struct node);
    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = item;
    p->next = ptr;
    ptr->next = NULL;
    return start;
}

struct node *createList(struct node *start)
{
    int n, p;
    start = NULL;
    cout << "How many number you want to add? : " << endl;
    cin >> n;
    if (n == 0)
    {
        return start;
    }
    cout << "Enter the first element to add the list : " << endl;
    cin >> p;
    start = insertAtFirst(start, p);
    cout << "Enter the other element to add the list : " << endl;
    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        start = insertAtLast(start, p);
    }
    cout << "The Singlely linked list is : " << endl;
    return start;
}

void Traversal(struct node *start)
{
    if (start == NULL)
    {
        cout << "List is empty.";
    }
    while (start != NULL)
    {
        cout << start->data << " ";
        start = start->next;
    }
    cout << endl;
}

// Here we count the occurrence of element frrom question 1.
void countElement(struct node *start, int item)
{
    int count = 0;
    while (start != NULL)
    {
        if (start->data == item)
        {
            count++;
        }
        start = start->next;
    }
    if (count != 0)
    {
        cout << "The number of occurrence of " << item << " is : " << count << endl;
    }
    else
    {
        cout << "The item " << item << " not present in the list." << endl;
    }
}

// Here we find the maximum and minimum value from question 2.
void MaxMin(struct node *start)
{
    int min = start->data;
    int max = start->data;
    while (start != NULL)
    {
        if (start->data < min)
        {
            min = start->data;
        }

        if (start->data > max)
        {
            max = start->data;
        }
        start = start->next;
    }
    cout << "The minimum value is : " << min << endl;
    cout << "The maximum value is : " << max << endl;
}

int main()
{
    int n;
    struct node *head;
    head = new (struct node);
    head = createList(head);
    Traversal(head);
    cout << "Which element you want to count? : " << endl;
    cin >> n;
    countElement(head, n);
    MaxMin(head);
}