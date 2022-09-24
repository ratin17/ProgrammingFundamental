#include<bits/stdc++.h>
using namespace std;

template <typename N> class Node{
    public:
    int value;
    Node* Next;

    Node(N val){
        value=val;
        Next=NULL;
    }
};


template <typename Q> class Queue{
    public:
    Node* <Q> front;
    Node* <Q> rear;

    Queue(){
        front =NULL;
        rear=NULL;
    }

    void push(Q val){
        Node* <Q> newNode=new Node <Q> (val);

        if(rear==NULL){
            front=newNode;
            rear=newNode;
            return ;
        }

        rear->Next=newNode;
        rear=rear->Next;
    }

    void pop(){
        Q popData;
        if(front==NULL){
            return INT_MIN;
        }
       Node* <Q> delNode=front;
       popData=front->value;
       front=front->Next;
       if(front==NULL)rear=NULL;
       delete delNode;
       //return popData;
    }


    Q Front(){
        return front->value;
    }

    Q Back(){
        return rear->value;
    }

    bool empty(){
        if(front==NULL)return true;
        else return false;
    }
};
