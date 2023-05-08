#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

struct Node {
    int val;
    Node *next;
};

void push_front(Node *&head, int a)
{
    Node *newNode = new Node;
    newNode->val = a;
    newNode->next = head;
    head = newNode;
}

void push_back(Node *&head, int a)
{
    Node *newNode = new Node;
    newNode->val = a;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = newNode;
    }
}

void pop_back(Node *&head) 
{
    if (head == NULL || head->next == NULL)
    {
        head = NULL;
        return;
    }
        
    Node *tail = head;
    while (tail->next->next != NULL)
    {
        tail = tail->next;
    }
    Node *target = tail->next;
    delete target;
    tail->next = NULL;
}

void pop_front(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        head = NULL;
        return;
    }
    Node *newHead = head->next;
    delete head;
    head = newHead;
}

void remove(Node *&head)
{
    Node *dummy = new Node;
    Node *prev = dummy;
    prev->next = head;
    for (Node *current = head; current != NULL; current = current->next)
    {
        if (current->val == 10)
        {
            prev->next = current->next;
            delete current;
            current = prev;
        }
        else
        {
            prev = prev->next;
        }
    }
    head = dummy->next;
}

void print(Node *head)
{
    for (Node *p = head; p != NULL; p = p->next)
    {
        cout << p->val << ' ';
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    cout << "zsh: segmentation fault  " << argv[0] << endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1};
    Node *head = NULL;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        push_back(head, arr[i]);
    print(head);

    pop_back(head);
    print(head);

    pop_front(head);
    print(head);

    remove(head);
    print(head);
}