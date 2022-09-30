#include <bits/stdc++.h>

using namespace std;


class Node{
    public:
    int value;
    Node *Next;

    Node(int val){
        value=val;
        Next=NULL;
    }
};

void printList(Node *node){
    if(node==NULL){
        return;
    }
    while (node != NULL){
        if(node->value%2==0)cout<<-1;
        else cout<<node->value;
        if(node->Next!=NULL)cout<<" -> ";
        node = node->Next;
    }
    cout<<endl<<endl;
}

void insertAtTail(Node* &Head, int val){
    
    Node* newNode=new Node(val);

    if(Head==NULL){
        Head=newNode;
        return;
    }
    
    Node* temp=Head;
    while(temp->Next!=NULL)temp=temp->Next;
    temp->Next=newNode;
    
}

int main(){

    Node* head = NULL;

    int n;
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        insertAtTail(head,val);
    }
    
    printList(head);
    
    return 0;
}

