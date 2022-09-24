#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void spacePrint(int n);


void printTree(Node* root,int level){
    if(root==NULL)return;

    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<endl;
        return;
    }
    else{
        cout<<endl;
        spacePrint(level);
        cout<<"Root : "<<root->data<<endl;

    }

    if(root->left!=NULL){
        spacePrint(level);
        cout<<"Left : ";
        printTree(root->left,level+1);
    }

    if(root->left!=NULL){
        spacePrint(level);
        cout<<"Right : ";
        printTree(root->right,level+1);
    }

}


void spacePrint(int n){
    while(n--)cout<<"    ";
}


void inOrder(Node* root,string &s){
    if(root==NULL)return;

    inOrder(root->left,s);

    s+=to_string(root->data);
    s+=" ";

    inOrder(root->right,s);
}


void preOrder(Node* root,string &s){
    if(root==NULL)return;

    s+=to_string(root->data);
    s+=" ";

    inOrder(root->left,s);
    inOrder(root->right,s);
}


void postOrder(Node* root,string &s){
    if(root==NULL)return;

    inOrder(root->left,s);
    inOrder(root->right,s);

    s+=to_string(root->data);
    s+=" ";
}


void levelOrder(Node* root,string &s){

    if(root==NULL)return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(true){
        if(q.front()==NULL){
            q.pop();
            if(q.empty())break;
            q.push(NULL);
            s+=", ";
        }
        else{
            s=s+to_string(q.front()->data)+" ";
            if(q.front()->left!=NULL)q.push(q.front()->left);
            if(q.front()->right!=NULL)q.push(q.front()->right);
            q.pop();
        }
    }

}


 Node* invert_tree(Node* root){

    if (root!=NULL) return NULL;

    stack<Node*> t;
    t.push(root);

    while (!t.empty()){
        Node* curr = t.top();
        t.pop();

        swap(curr->left, curr->right);

        if (curr->right)t.push(curr->right);
        
        if (curr->left)t.push(curr->left);
    }
    return root;
}

int main(){
    int n,value,left,right;
    cin>>n;
    Node* allNodes[n];
    for(int i=0;i<n;i++){
        allNodes[i]=new Node(-1);
    }

    for(int i=0;i<n;i++){
        cin>>value>>left>>right;
        allNodes[i]->data=value;

        if(left!=-1)allNodes[i]->left=allNodes[left];
        if(right!=-1)allNodes[i]->right=allNodes[right];

    }

    printTree(allNodes[0],0);

    string in="";
    string pre="";
    string post="";
    string level="";

    // inOrder(allNodes[0],in);
    // cout<<endl<<"Inorder : "<<in<<endl;

    // preOrder(allNodes[0],pre);
    // cout<<endl<<"Preorder : "<<pre<<endl;

    // postOrder(allNodes[0],post);
    // cout<<endl<<"Postorder : "<<post<<endl;

    // levelOrder(allNodes[0],level);
    // cout<<endl<<"levelorder : "<<level<<endl;

    printTree(invert_tree(allNodes[0]),0);



    return 0;
}




/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

*/