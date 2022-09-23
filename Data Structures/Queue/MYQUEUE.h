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
