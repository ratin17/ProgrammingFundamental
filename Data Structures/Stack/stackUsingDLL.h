#include <bits/stdc++.h>
//#define NULL _null;
using namespace std;

class Node{
public:
    int val;
    Node *Prev;
    Node *Next;

    Node(int v){
        val=v;
        Prev=NULL;
        Next=NULL;
    }

};

class Stack{
    Node *Head;
    Node *Top;
    int countNode;

    Stack(){
        Head=NULL;
        Top=NULL;
        countNode=0;
    }

    void push(int v){
        Node *newNode=new Node(v);
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

    int pop(){
        Node *popNode=Top;
        int popValue=popNode->val;

        if(Head==NULL){
            cout<<"UnderFlow"<<endl;
            return;
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
        return popValue;
    }

    int size(){
        return countNode;
    }

    int top(){
        return Top->val;
    }

    bool empty(){
        if(countNode==0)return true;
        else return false;
    }

};

