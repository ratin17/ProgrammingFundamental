#include <bits/stdc++.h>

using namespace std;

template <typename N> class Node{
public:
    N val;
    Node *Prev;
    Node *Next;

    Node(N v){
        val=v;
        Prev=NULL;
        Next=NULL;
    }
};


template <typename S> class Stack{
public:
    Node <S> *Head;
    Node <S> *Top;
    S countNode;

    Stack(){
        Head=NULL;
        Top=NULL;
        countNode=0;
    }

    void push(S v){
        Node <S> *newNode=new Node <S> (v);
        if(Head==NULL){
            Head=newNode;
            Top=newNode;
            countNode++;
            return;
        }
        else{
            Top->Next=newNode;
            newNode->Prev=Top;
            Top=newNode;
            countNode++;
        }
    }

    void pop(){
        Node <S> *popNode=Top;
        S popValue=popNode->val;

        if(Head==NULL){
            cout<<"UnderFlow"<<endl;
            //return -1;
        }
        else if(Top==Head){
            Head=NULL;
            Top=NULL;
            countNode--;
        }
        else{
            popNode->Prev->Next=NULL;
            Top=popNode->Prev;
            countNode--;
        }

        delete popNode;
        //return popValue;
    }

    S size(){
        return countNode;
    }

    S top(){
        return Top->val;
    }

    bool empty(){
        if(Head==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    int mid(){
        Node <S> *fast=Head;
        Node <S> *slow=Head;
        if(slow==NULL)return -1;

        while(fast!=NULL && fast->Next!=NULL){
            slow=slow->Next;
            fast=fast->Next->Next;
        }
        return slow->val;
    }

    void show(){
        Node <S> *temp=Head;
        cout<<"(Head)";
        while(temp!=NULL){
            cout<<temp->val;
            if(temp->Next!=NULL)cout<<" ->";
            temp=temp->Next;
        }
        cout<<"(Top)"<<endl;
    }

};

