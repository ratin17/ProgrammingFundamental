#include <bits/stdc++.h>

using namespace std;

class MyLinkedList{
public:
    int value;
    MyLinkedList *Next;
    MyLinkedList* Head;

    MyLinkedList(){
        this->Head=NULL;
    }

    MyLinkedList(int val){
        this->value = val;
        this->Next = NULL;
    }
    

    int length(){
        MyLinkedList* node=Head;
        int count =0;
        while (node != NULL){
            count++;
            node = node->Next;
        }
        return count;
    }

    int get(int index){
        MyLinkedList* temp=Head;
        if(Head==NULL)return -1;

        int count=0;
        while(count!=index){
            temp=temp->Next;
            if(temp==NULL)return -1;
            count++;
        }

        return temp->value;
    }

    void addAtHead(int val) {
        MyLinkedList* newNode = new MyLinkedList(val);

        if (Head == NULL){
            Head = newNode;
            return;
        }

        newNode->Next = Head;
        Head = newNode;
    }
    
    void addAtTail(int val) {
        MyLinkedList* newNode = new MyLinkedList(val);

        if (Head == NULL)
        {
            Head = newNode;

            return;
        }

        MyLinkedList *temp = Head;
        while (temp->Next != NULL)
            temp = temp->Next;
        temp->Next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0){
            addAtHead(val);
            return;
        }
        if (index==this->length()){
            this->addAtTail(val);
            return;
        }
        if (index>this->length()){
            return;
        }

        int count = 0;
        MyLinkedList *newNode = new MyLinkedList(val);
        MyLinkedList *temp = Head;

        while (++count != index)
        {
            temp = temp->Next;
        }
        newNode->Next = temp->Next;
        temp->Next = newNode;
    }
    
    void deleteAtIndex(int pos){
        MyLinkedList* temp=Head;
        if(temp==NULL){
            return;
        }
        if(pos>=length()){
            return;
        }
        if(pos==0){
            Head=temp->Next;
            delete temp;
            return;
        }

        int count =0;
        while(++count!=pos)temp=temp->Next;
        MyLinkedList* delNode = temp->Next;
        temp->Next=delNode->Next;
        delete delNode;
    }

    void show(){
        MyLinkedList* temp=Head;
        if(temp==NULL){
            cout<<endl<<"Nothing to show"<<endl;
            return;
        }

        while(temp!=NULL){
            cout<<temp->value;
            if(temp->Next!=NULL)cout<<" -> ";
            temp=temp->Next;
        }
        cout<<endl;
    }    

    int searchByValue(int key){
        MyLinkedList* temp=Head;
        int count=-1;
        while(temp!=NULL){
            count++;
            if(temp->value==key)return count;
            temp=temp->Next;
        }
        return -1;
    }

    

};
    


int main(){
    MyLinkedList obj = MyLinkedList();
    
    obj.show();

    cout<<"0 : Exit"<<endl;
    cout<<"1 : Show Current List"<<endl;
    cout<<"2 : Inser at Head"<<endl;
    cout<<"3 : Inser at Tail"<<endl;
    cout<<"4 : List length"<<endl;
    cout<<"5 : Insert at any Position"<<endl;
    //cout<<"6 : Search By Value"<<endl;
    //cout<<"7 : Delete from Head"<<endl;
    //cout<<"8 : Delete from Tail"<<endl;
    cout<<"9 : Delete from any Position"<<endl;
    // cout<<"10 : Delete by Value"<<endl;
    // cout<<"11 : Reverse List"<<endl;
    // cout<<"12 : Reverse List Recursive"<<endl;
    // cout<<"13 : Get the mid element"<<endl;
    // cout<<"14 : Make a Cycle"<<endl;
    // cout<<"15 : Detect Cycle"<<endl;
    // cout<<"16 : Remove Cycle"<<endl;
    
    

    int c=1,v,p,k;
    while(c!=0){
        cout<<endl<<"Enter choice:";
        cin>>c;

        if(c==1)obj.show();

        else if(c==2){
            cout<<"Enter value to be inserted at Head:";
            cin>>v;
            obj.addAtHead(v);
        }

        else if(c==3){
            cout<<"Enter value to be inserted at Tail:";
            cin>>v;
            obj.addAtTail(v);
        }
        else if(c==4){
            cout<<endl<<"List Length :"<<obj.length()<<endl;
        }
        else if(c==5){
            cout<<"Enter Value & Position to be inserted:";
            cin>>v>>p;
            obj.addAtIndex(p,v);
        }
        else if(c==9){
            cout<<"Enter position to delete:";
            cin>>p;
            obj.deleteAtIndex(p);
        }
        
    }
    
    return 0;
}