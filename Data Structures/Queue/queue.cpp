#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* Next;

    Node(int val){
        value=val;
        Next=NULL;
    }
};


class Queue{
    public:
    Node* front;
    Node* rear;

    Queue(){
        front =NULL;
        rear=NULL;
    }

    void push(int val){
        Node* newNode=new Node(val);

        if(rear==NULL){
            front=newNode;
            rear=newNode;
            return ;
        }

        rear->Next=newNode;
        rear=rear->Next;
    }

    int pop(){
        int popData;
        if(front==NULL){
            return INT_MIN;
        }
       Node* delNode=front;
       popData=front->value;
       front=front->Next;
       if(front==NULL)rear=NULL;
       delete delNode;
       return popData;
    }

    void show(){
        Node* temp=front;
        if(temp==NULL){
            cout<<endl<<"No element"<<endl;
            return ;
        }
        cout<<endl<<"Queue : ";
        while(temp!=NULL){
            cout<<temp->value<<" ";
            temp=temp->Next;
        }
        cout<<endl<<endl;
    }

    int getFront(){
        return front->value;
    }

    int getBack(){
        return rear->value;
    }

    bool empty(){
        if(front==NULL)return true;
        else return false;
    }
};



int main(){

    Queue q;
    q.push(8);
    q.push(7);
    q.push(7);
    q.pop();
    q.push(3);
    q.show();
    
    cout<<"0 : Exit"<<endl;
    cout<<"1 : Show Current Queue"<<endl;
    cout<<"2 : Push"<<endl;
    cout<<"3 : Pop"<<endl;
    cout<<"4 : Show Front"<<endl;
    cout<<"5 : Show Back"<<endl;
    cout<<"6 : Check Empty"<<endl;
    
    int c=1,v,p,k;
    while(c!=0){
        cout<<endl<<"Enter choice:";
        cin>>c;

        if(c==1)q.show();

        else if(c==2){
            cout<<"Enter Value to push :";
            cin>>v;
            q.push(v);
        }
        else if(c==3){
            cout<<endl<<"Pop Value : "<<q.pop()<<endl;
        }
        else if(c==4){
            cout<<endl<<"Front Value : "<<q.getFront()<<endl;
        }
        else if(c==5){
            cout<<endl<<"Back Value : "<<q.getBack()<<endl;
        }
        else if(c==6){
            if(q.empty())cout<<"Queue is Empty !"<<endl;
            else cout<<"Queue is not Empty !"<<endl;
        }

        

    }


    return 0;
}