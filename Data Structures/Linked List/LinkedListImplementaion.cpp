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
        cout<<endl<<"Nothing in the List !"<<endl;
        return;
    }
    cout<<endl<<"List :";
    while (node != NULL){
        cout<<" "<<node->value;
        node = node->Next;
    }
    cout<<endl<<endl;
}


void reversedListPrint(Node* head)
{
    if (head == NULL)
    return;

    reversedListPrint(head->Next);

    cout << head->value << " ";
}

//Head is a Node pointer which references head
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

//just for testing some pointer issues
void printTest(int* &p){
    cout<<endl<<"Test :"<<*p<<endl;
}

int listLength(Node* node){
    int count =0;
    while (node != NULL){
        count++;
        node = node->Next;
    }
    return count;
}

void insertAtAnyPostion(Node* &Head,int val,int pos){
    if(pos==1){
        insertAtHead(Head,val);
        return;
    }
    if(pos>listLength(Head)){
        insertAtTail(Head,val);
        return;
    }

    int count=1;
    Node *newNode=new Node(val); 
    Node* temp=Head;

    while(++count!=pos ){
        temp=temp->Next;
    }
    newNode->Next=temp->Next;
    temp->Next=newNode;
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

void deleteByValue(Node* &Head,int val){
    int pos=searchByValue(Head,val);
    while(pos!=-1){
        deleteFromAnyPosition(Head,pos);
        pos=searchByValue(Head,val);
    }
}

void reverseList(Node* &Head){
    Node* prev=NULL;
    Node* cur=Head;
    Node* next=Head->Next;

    while(true){
       cur->Next=prev;
       if(next==NULL)break;
       prev=cur;
       cur=next;
       next=next->Next;
    }
    Head=cur;

    cout<<endl<<"List is Reversed"<<endl;
}

Node* reverseListRecursive(Node* &Head){
    
    //base call
    if(Head->Next==NULL)return Head;

    Node* newHead=reverseListRecursive(Head->Next);
    Head->Next->Next=Head;
    Head->Next=NULL;

    return newHead;
}


int main(){

    Node* head = NULL;

    insertAtTail(head, 2);
    insertAtHead(head,1);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    printList(head);
    cout<<"0 : Exit"<<endl;
    cout<<"1 : Show Current List"<<endl;
    cout<<"2 : Inser at Head"<<endl;
    cout<<"3 : Inser at Tail"<<endl;
    cout<<"4 : List length"<<endl;
    cout<<"5 : Insert at any Position"<<endl;
    cout<<"6 : Search By Value"<<endl;
    cout<<"7 : Delete from Head"<<endl;
    cout<<"8 : Delete from Tail"<<endl;
    cout<<"9 : Delete from any Position"<<endl;
    cout<<"10 : Delete by Value"<<endl;
    cout<<"11 : Reverse List"<<endl;
    cout<<"12 : Reverse List Recursive"<<endl;
    

    int c=1,v,p,k;
    while(c!=0){
        cout<<endl<<"Enter choice:";
        cin>>c;

        if(c==1)printList(head);

        else if(c==2){
            cout<<"Enter value to be inserted at Head:";
            cin>>v;
            insertAtHead(head,v);
        }

        else if(c==3){
            cout<<"Enter value to be inserted at Tail:";
            cin>>v;
            insertAtTail(head,v);
        }
        else if(c==4){
            cout<<endl<<"List Length :"<<listLength(head)<<endl;
        }
        else if(c==5){
            cout<<"Enter Value & Position to be inserted:";
            cin>>v>>p;
            insertAtAnyPostion(head,v,p);
        }
        else if(c==6){
            cout<<"Enter value to search:";
            cin>>v;
            cout<<v<<" found at pos: "<<searchByValue(head,v)<<endl;
        }
        else if(c==7){
            deleteFromHead(head);
        }
        else if(c==8){
            deleteFromTail(head);
        }
        else if(c==9){
            cout<<"Enter position to delete:";
            cin>>p;
            deleteFromAnyPosition(head,p);
        }
        else if(c==10){
            cout<<"Enter value to delete:";
            cin>>v;
            deleteByValue(head,v);

        }
        else if(c==11){
            reverseList(head);

        }
        else if(c==12){
            head=reverseListRecursive(head);
            cout<<endl<<"List is Reversed Recursivley"<<endl;
        }
    }
    
    return 0;
}

