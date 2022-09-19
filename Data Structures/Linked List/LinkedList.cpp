#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

void reversedListPrint(Node* head)
{
    if (head == NULL)
    return;

    reversedListPrint(head->next);

    cout << head->data << " ";
}

void insertToHead(Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void insertToTail(Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    Node *last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return;
}



int main(){

    Node* head = NULL;
    insertToHead(&head, 5);
    insertToTail(&head, 1);
    insertToTail(&head, 9);
    insertToHead(&head, 7);

    cout<<"Elements of the list:"<<endl;
    printList(head);
    cout<<endl<<"Elements of the list in reverse order:"<<endl;
    reversedListPrint(head);
    return 0;
}
