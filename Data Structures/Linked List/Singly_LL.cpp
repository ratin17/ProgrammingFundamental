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


//prototypes
bool hasCycle(Node *Head);
void makeCycle(Node* &Head,int pos);
void removeCycle(Node* &Head);


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


int getMid(Node* Head){
    Node* slow=Head;
    Node* fast =Head;

    while(fast!=NULL && fast->Next!=NULL){
        slow=slow->Next;
        fast=fast->Next->Next;
    }
    return slow->value;
}


bool hasCycle(Node *Head){
    Node* slow=Head;
    Node* fast =Head;
    
    //if No Node or for a  single non-circular list
    if(slow==NULL || slow->Next==NULL)return false;

    do{
        slow=slow->Next;
        fast=fast->Next->Next;

        if(slow==fast)return true;
    }while (fast!=NULL && fast->Next!=NULL);

    return false;
    
}


void makeCycle(Node* &Head,int pos){
    if(Head==NULL){
        cout<<endl<<">>>> No eleemnt in the list ! "<<endl;
        return;
    }

    if(hasCycle(Head))removeCycle(Head);
    
    Node* temp=Head;
    int count=1;
    Node* startNode;

    while(temp->Next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->Next;
        count++;
    }
    temp->Next=startNode;

    cout<<endl<<">>>> Cycle created at pos: "<<pos<<endl;
}



void removeCycle(Node* &Head){
    Node* slow=Head;
    Node* fast =Head;
    
    if(!hasCycle(Head)){
        cout<<endl<<">>>> No Cycle found to remove"<<endl;
    }

    do{
        slow=slow->Next;
        fast=fast->Next->Next;

        if(slow==fast)break;
    }while (fast!=NULL && fast->Next!=NULL);

    fast=Head;
    while(slow->Next!=fast->Next){
        slow=slow->Next;
        fast=fast->Next;
    }
    slow->Next=NULL;

    cout<<endl<<">>>> Cycle removed"<<endl;
}




int main(){

    Node* head = NULL;
    Node* cycleNode=NULL;

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
    cout<<"13 : Get the mid element"<<endl;
    cout<<"14 : Make a Cycle"<<endl;
    cout<<"15 : Detect Cycle"<<endl;
    cout<<"16 : Remove Cycle"<<endl;
    

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
        else if(c==13){
            cout<<endl<<"Midd Element: "<<getMid(head)<<endl;
        }
        else if(c==14){
            cout<<"Enter pos :";
            cin>>p;
            makeCycle(head,p);
        }
        else if(c==15){
            if(hasCycle(head))
            cout<<endl<<">>>> Cycle found !"<<endl;
            else
            cout<<endl<<">>>> No Cycle found :)"<<endl;
            
        }
        else if(c==16){
            removeCycle(head);
        }

    }
    
    return 0;
}

