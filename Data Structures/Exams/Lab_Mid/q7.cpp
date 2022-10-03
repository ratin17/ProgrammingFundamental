#include <bits/stdc++.h>
using namespace std;
  

class Node {
public:
    int value;
    Node* next;
    Node(int val){
        value=val;
        next=NULL;
    }
};
  

Node* reverse(Node* head, int k){
    Node * current = head;
    Node * next = NULL, * prev = NULL;
    int count = 0;

  while (current != NULL && count < k) {
    next = current -> next;
    current -> next = prev;
    prev = current;
    current = next;
    count++;
  }

  if (next != NULL)
    head -> next = reverse(next, k);

  return prev;
}
  
void insertAtTail(Node* &Head, int val){
    
    Node* newNode=new Node(val);

    if(Head==NULL){
        Head=newNode;
        return;
    }
    
    Node* temp=Head;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=newNode;
    
}
  
void printList(Node *node){
    if(node==NULL){
        return;
    }
    cout<<endl<<"List : ";
    while (node != NULL){
        cout<<node->value;
        if(node->next!=NULL)cout<<" -> ";
        node = node->next;
    }
    cout<<endl<<endl;
}
  
int main(){
    Node* head = NULL;
    
    int n;
    cin>>n;
    int val;
    while(n--){
        cin>>val;
        insertAtTail(head,val); 
    }
    int k;
    cin>>k;
    head = reverse(head, k);
    printList(head);
  
    return (0);
}