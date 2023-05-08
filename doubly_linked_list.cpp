#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;
};

void ReverseDoublyLinkedList(Node **head_ptr, Node **tail_ptr) {
    Node *tmp = NULL;
    Node *current = *head_ptr;
    while (current != NULL)
    {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }
    if (tmp != NULL)
    {
        *tail_ptr = *head_ptr;
        *head_ptr = tmp->prev;
    }
}

int main()
{
    Node *head = new Node;
    Node *tail = new Node;
    head->val = 1;
    head->next = tail;
    head->prev = NULL;
    tail->val = 2;
    tail->next = NULL;
    tail->prev = head;
    Node **head_ptr = &head;
    Node **tail_ptr = &tail;

    ReverseDoublyLinkedList(head_ptr, tail_ptr);

    cout << head->val << " " << tail->val;
}

