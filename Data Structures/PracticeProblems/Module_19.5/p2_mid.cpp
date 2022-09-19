#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int value;
    Node *Next;
    Node* Prev;

    Node(int val){
        value=val;
        Next=NULL;
        Prev=NULL;
    }
};

void insertAtTail(Node* &Head, int val){
    
    Node* newNode=new Node(val);

    if(Head==NULL){
        Head=newNode;
        return;
    }
    
    Node* temp=Head;
    while(temp->Next!=NULL)temp=temp->Next;
    temp->Next=newNode;
    newNode->Prev=temp;
    
}

int findMiddle(Node* &Head){
    Node* begin=Head;
    Node* end=Head;
    Node* mid;

    while(end->Next!=NULL)end=end->Next;
    
    if(end==begin)return begin->value;

    while(true){
        end=end->Prev;
        if(end==begin)return begin->value;
        begin=begin->Next;
        if(end==begin)return begin->value;
    }

}


int main(){

    Node* head = NULL;

    insertAtTail(head, 2);
    insertAtTail(head, 7);
    insertAtTail(head, 9);
    insertAtTail(head, 1);
    
    cout<<endl<<"Current Middle : "<<findMiddle(head)<<endl;
    

    
    
    return 0;
}

