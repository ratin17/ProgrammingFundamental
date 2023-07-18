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

void printList(Node *node){
    if(node==NULL){
        cout<<endl<<"Nothing in the List !"<<endl;
        return;
    }
    // cout<<endl<<"List : ";
    while (node != NULL){
        cout<<node->value;
        if(node->Next!=NULL)cout<<" ";
        node = node->Next;
    }
    cout<<endl<<endl;
}


void reversedListPrint(Node* head){
    Node* temp=head;
    while(temp->Next!=NULL)temp=temp->Next;
    
    while(temp!=NULL){
        cout<<temp->value;
        if(temp->Prev!=NULL)cout<<" ";
        temp=temp->Prev;
    }
    cout<<endl<<endl;
}

//Head is a Node pointer which references head
void insertAtHead(Node* &Head, int val){
    Node* newNode=new Node(val);

    if(Head==NULL){
        Head=newNode;
        return;
    }

    newNode->Next=Head;
    Head->Prev=newNode;
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
    newNode->Prev=temp;
    
}

//just for testing some pointer issues
void printTest(int* &p){
    cout<<endl<<"Test :"<<*p<<endl;
}

int size(Node* node){
    int count =0;
    while (node != NULL){
        count++;
        node = node->Next;
    }
    return count;
}

void insertAtAnyPostion(Node* &Head,int val,int pos){
    if(pos==0){
        insertAtHead(Head,val);
        return;
    }
    if(pos==size(Head)){
        insertAtTail(Head,val);
        return;
    }
    if(pos>size(Head)){
        cout<<"Invalid"<<endl;
        return;
    }

    int count=pos-1;
    Node *newNode=new Node(val); 
    Node* temp=Head;

    while(count--){
        temp=temp->Next;
    }

    newNode->Next=temp->Next;
    newNode->Prev=temp;
    temp->Next=newNode;
    newNode->Next->Prev=newNode;
}

int searchByValue(Node *Head,int key){
    Node* temp=Head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(temp->value==key)return count;
        temp=temp->Next;
    }
    return -1;
}

void deleteFromHead(Node* &Head){
    Node* temp=Head;
    if(temp==NULL){
        cout<<"Nothing to delete !"<<endl;
        return;
    }
    Head=temp->Next;
    Head->Prev=NULL;
    cout<<endl<<temp->value<<" Deleted from head"<<endl;
    delete temp;
}

void deleteFromTail(Node* &Head){
    Node* temp=Head;
    if(temp==NULL){
        cout<<"Nothing to delete !"<<endl;
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
    if(pos>size(Head)){
        cout<<"Deletion Index out of bound ("<<size(Head)<<") !"<<endl;
        return;
    }
    if(pos==1){
        deleteFromHead(Head);
        return;
    }
    if(pos==size(Head)){
        deleteFromTail(Head);
        return;
    }

    int count =0;
    while(++count!=(pos-1))temp=temp->Next;
    Node* delNode = temp->Next;
    temp->Next=delNode->Next;
    delNode->Next->Prev=temp;
    cout<<endl<<delNode->value<<" Deleted from pos : "<<pos<<endl;
    delete delNode;

}

void deleteByValue(Node* &Head,int val){
    int pos=searchByValue(Head,val);
    while(pos!=-1){
        deleteFromAnyPosition(Head,pos);
        pos=searchByValue(Head,val);
    }
}

void reverseList(Node* &Head){
    Node* temp;
    Node* itr;
    Node* cur=Head;

    while(cur!=NULL){
        itr=cur->Next; //for preserving next node to iterate

        temp=cur->Next;
        cur->Next=cur->Prev;
        cur->Prev=temp;

        //passing the New Head rightwards
        Head=cur;

        cur=itr;
    }


    //cout<<endl<<"List is Reversed"<<endl;
}


Node* reverseListRecursive(Node* node){
    if (!node)return NULL;
 
    Node* temp = node->Next;
    node->Next = node->Prev;
    node->Prev = temp;
 
    if (!node->Prev)
        return node;
 
    return reverseListRecursive(node->Prev);
}

bool isSame(Node* head1,Node* head2){
    if(size(head1)!=size(head2)){
        //cout<<"size"<<endl;
        return false;
    }

    while(head1!=NULL&&head2!=NULL){
        if(head1->value!=head2->value){
            //cout<<"size"<<endl;
            return false;
        }
        head1=head1->Next;
        head2=head2->Next;
    }
    return true;
}

bool isPalindrome(Node* head){
    Node* forw=head;
    Node* back=head;

    while(back->Next!=NULL){
        back=back->Next;
    }
    int s=size(head);
    s=s/2;

    while(s--){
        if(forw->value!=back->value)return false;
        forw=forw->Next;
        back=back->Prev;
    }

    return true;

}

int main(){

    Node* head = NULL;
   

    int v;
    while(true){
        cin>>v;
        if(v==-1)break;
        insertAtTail(head,v);
    }

    int q,p,va;
    cin>>q;
    while(q--){
        cin>>p>>va;
        insertAtAnyPostion(head,va,p);

        printList(head);
        reversedListPrint(head);

    }

     






    
    return 0;
}

