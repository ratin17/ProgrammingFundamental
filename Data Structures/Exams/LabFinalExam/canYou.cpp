#include<bits/stdc++.h>
using namespace std;
int c=0;
class Node{
    public:
    char data;
    Node* left, * right;

    Node(char c){
        data=c;
        left=NULL;
        right=NULL;
    }
};

bool isPalindrome(char str[]){
    int l = 0;
    int h = strlen(str) - 1;
 
    while (h > l){
        if (str[l++] != str[h--])return false;
        
    }
    return true;
}


void printPathsRecur(Node* node, char path[], int pathLen){
    if (node == NULL)
        return;
     
    path[pathLen] = node->data;
    pathLen++;
     
    if(node->left == NULL && node->right == NULL){
        if(isPalindrome(path))c++;
    }
    else{
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
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



int main(){
    string s;
    cin >> s;
    int a;
    cin >> a;
   
    Node* root=new Node(s[a]);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* presentRoot=q.front();
        q.pop();
        int x,y;
        cin >> x >>y;
        Node* n1 = NULL;
        Node* n2 = NULL;
        if(x!=-1){
            n1=new Node(s[x]);
        }

        if(y!=-1){
            n2=new Node(s[y]);
        }

        presentRoot->left = n1;
        presentRoot->right = n2;
 
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    } 

    string level="";
    levelOrder(root,level);
    //cout<<endl<<"levelorder : "<<level<<endl;
    
    //rootToLeaf(root,a);
    char ch[20];
    printPathsRecur(root,ch,0);
    cout<<c<<endl;

}
