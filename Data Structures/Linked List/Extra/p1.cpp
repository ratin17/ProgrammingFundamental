#include <bits/stdc++.h>

using namespace std;


class Node{

    public:
        int value;
        Node *Next;

        Node(int val){
            this->value=val;
            this->Next=NULL;
        }
};

void printList(Node *node){
    if(node==NULL){
        cout<<endl<<"Nothing in the List !"<<endl;
        return;
    }
    cout<<endl<<"List : ";
    while (node != NULL){
        cout<<node->value;
        if(node->Next!=NULL)cout<<" -> ";
        node = node->Next;
    }
    cout<<endl<<endl;
}

void insertAtHead(Node* &Head, int val){
    Node* newNode=new Node(val);

    if(Head==NULL){
        Head=newNode;
        return;
    }

    newNode->Next=Head;
    Head=newNode;
    
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

int getSize(Node* node){
    int count =0;
    while (node != NULL){
        count++;
        node = node->Next;
    }
    return count;
}

bool hasDupli(Node* node){
    int freq[101];

    for(int i=0;i<101;i++){
        freq[i]=0;
    }

    while(node!=NULL){
        freq[node->value]++;
        if(freq[node->value]>1){
            return true;
        }
        node=node->Next;
    }

    return false;
}

int getValueAt(Node* head,int pos){
    
    while(pos--){
        head=head->Next;
    }
    return head->value;
}

void findMiddle(Node* head){
    int size=getSize(head);
    int pos=size/2;

    if(size%2==0){
        int m1=getValueAt(head,pos-1);
        int m2=getValueAt(head,pos);
        cout<<m1<<" "<<m2<<endl;
    }
    else{
        cout<<getValueAt(head,pos)<<endl;
    }
}

bool checkSorted(Node* head){
    
    if(head==NULL)return true;
    
    int v1,v2;

    v1=head->value;
    v2=v1;

    while(head->Next!=NULL){
        v1=v2;
        head=head->Next;
        v2=head->value;

        if(v2<v1)return false;
    }
    return true;
}

void insertAtAnyPostion(Node* &Head,int val,int pos){
    if(pos==0){
        insertAtHead(Head,val);
        printList(Head);
        return;
    }
    if(pos>getSize(Head)){
        cout<<"Invalid Position !"<<endl;
        printList(Head);
        return;
    }

    Node *newNode=new Node(val); 
    Node* temp=Head;

    pos--;
    while(pos-- ){
        temp=temp->Next;
    }
    newNode->Next=temp->Next;
    temp->Next=newNode;

    printList(Head);
}

int main(){
    Node* head = NULL;

    int v;
    while(true){
        cin>>v;
        if(v==-1)break;
        insertAtTail(head,v);
    }

    cout<<getSize(head)<<endl;
    //cout<<hasDupli(head)<<endl;
    //cout<<getValueAt(head,3)<<endl;
    //findMiddle(head);
    //cout<<checkSorted(head)<<endl;
    insertAtAnyPostion(head,67,0);
    insertAtAnyPostion(head,73,0);
    cout<<getSize(head)<<endl;

}

/*

4 0 1 100 7 -1


*/