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
        //cout<<endl<<"Nothing in the List !"<<endl;
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


int listLength(Node* node){
    int count =0;
    while (node != NULL){
        count++;
        node = node->Next;
    }
    return count;
}


void deleteFromHead(Node* &Head){
    Node* temp=Head;
    if(temp==NULL){
        //cout<<"Nothing to delete !"<<endl;
        return;
    }
    Head=temp->Next;
    //cout<<endl<<temp->value<<" Deleted from head"<<endl;
    delete temp;
}

void deleteFromTail(Node* &Head){
    Node* temp=Head;
    if(temp==NULL){
        //cout<<"Nothing to delete !"<<endl;
        return;
    }
    if(temp->Next==NULL){
        deleteFromHead(Head);
        return;
    }

    while(temp->Next->Next!=NULL)temp=temp->Next;

    Node* delNode=temp->Next;
    temp->Next=NULL;
    cout<<endl<<delNode->value<<" Deleted from tail"<<endl;
    delete delNode;

}



void deleteFromAnyPosition(Node* &Head,int pos){
    Node* temp=Head;
    if(temp==NULL){
        cout<<"Nothing to delete !"<<endl;
        return;
    }
    if(pos>listLength(Head)){
        cout<<"Deletion Index out of bound ("<<listLength(Head)<<") !"<<endl;
        return;
    }
    if(pos==1){
        deleteFromHead(Head);
        return;
    }
    if(pos==listLength(Head)){
        deleteFromTail(Head);
        return;
    }

    int count =0;
    while(++count!=(pos-1))temp=temp->Next;
    Node* delNode = temp->Next;
    temp->Next=delNode->Next;
    cout<<endl<<delNode->value<<" Deleted from pos : "<<pos<<endl;
    delete delNode;

}



int main(){

    Node* head = NULL;
    int k,m,n;
    cin>>k>>m>>n;
    int a[k];
    for(int i=0;i<k;i++){
        cin>>a[i];
        insertAtTail(head,a[i]);
    }
    
    vector<int>del;
    int t=n;
    for(int i=m+1;i<=k;i++){
        del.push_back(a[i-1]);
        t--;
        if(t==0){
            t=n;
            i=i+m-1;
        }
    }

    for(int i=0;i<del.size();i++){
        deleteFromAnyPosition(head,del[i]);
    }

    printList(head);
    
    return 0;
}

