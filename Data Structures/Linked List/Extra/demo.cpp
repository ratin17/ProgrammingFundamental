#include <bits/stdc++.h>

using namespace std;

// Node class
class Node{

    public:
        int value;
        Node *Next;

        Node(int val){
            this->value=val;
            this->Next=NULL;
        }
};



//print list

void printList(Node* head){
    if(head==NULL){
        cout<<"No elements to print"<<endl;
    }
    while(head!=NULL){
        cout<<head->value<<" ";
        head=head->Next;
    }
    cout<<endl;
}



//insert at head
void insertAtHead(Node* &Head, int val){
    Node* newNode=new Node(val);

    if(Head==NULL){
        Head=newNode;
        return;
    }

    newNode->Next=Head;
    Head=newNode;
    
}



//insert at tail

void insertAtTail(Node* &head, int val){
    Node* newNode=new Node(val);

    if(head==NULL){
        head=newNode;
        return;
    }

    Node* temp=head;

    while(temp->Next!=NULL){
        temp=temp->Next;
    }

    temp->Next=newNode;

}



//get size of the list

int getSize(Node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->Next;
    }
    return count;
}


//get value at position

int getAt(Node *head,int pos){
    
    while(pos--){
        head=head->Next;
    }
    return head->value;
}

//duplicate

bool hasDupli(Node* node){
    int f[101];

    for(int i=0;i<101;i++){
        f[i]=0;
    }

    while(node!=NULL){
        f[node->value]++;
        if(f[node->value]>1){
            return true;
        }
        node=node->Next;
    }

    return false;
}

//gett mid

void findMid(Node* head){
    int size=getSize(head);
    int pos=size/2;

    if(size%2==0){
        int m1=getAt(head,pos-1);
        int m2=getAt(head,pos);

        cout<<m1<<" "<<m2<<endl;
    }
    else{
        cout<<getAt(head,pos)<<endl;
    }

}


//insert at given position

void insertAt(Node * &head,int pos, int val){
    Node * newN =new Node(val);

    if(pos==0){
        insertAtHead(head,val);
        printList(head);
        return;
    }
    if(pos>getSize(head)){
        cout<<"Invalid !"<<endl;
        return ;
    }

    pos--;
    Node* temp=head;
    while(pos--){
        temp=temp->Next;
    }

    newN->Next=temp->Next;
    temp->Next=newN;

    printList(head);
}

void query(Node * &head){
    int q;
    cin>>q;

    while(q--){
        int val,pos;
        insertAt(head,pos,val);
    }
}

bool isSorted(Node * head){
    int v1,v2;
    
    v1=head->value;
    v2=head->value;

    while(head->Next!=NULL){
        v1=v2;
        head=head->Next;
        v2=head->value;

        if(v2<v1)return false;
    }

    return true;

}

int getMax(Node* head){
    int m=INT_MIN;

    while(head!=NULL){
        //cout<<head->value<<endl;
        if((head->value)>m)m=head->value;
        head=head->Next;
    }
    return m;
}



int main(){
    Node* head = NULL;

    // Node * head2=NULL;

    int v;

    while(true){
        cin>>v;
        if(v==-1)break;
        insertAtTail(head,v);
    }

   

    // cout<<getSize(head)<<endl;
    
    // if(hasDupli(head))cout<<"YES"<<endl;
    // else cout<<"No"<<endl;

    //findMid(head);

    // int q;
    // cin>>q;

    // while(q--){
    //     int p,va;
    //     cin>>p>>va;
    //     insertAt(head,p,va);
    // }

    // if(isSorted(head))cout<<"YES"<<endl;
    // else cout<<"No"<<endl;

    cout<<getMax(head)<<endl;




    
    return 0;
}
