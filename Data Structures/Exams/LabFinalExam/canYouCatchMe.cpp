#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* insertLevelOrder(vector<char> arr,int i, int n){
      Node *root = nullptr;
    if (i < n)
    {
        root = newNode(arr[i]);
          
        // insert left child
        root->left = insertLevelOrder(arr,
                   2 * i + 1, n);
  
        // insert right child
        root->right = insertLevelOrder(arr,
                  2 * i + 2, n);
    }
    return root;
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
    cin>>s;
    int l=1;
    int p,c=0;
    vector<char>a;
    for(int i=1;i<=l;i++){
        cin>>p;
        if(p!=-1){
            a.push_back(s[p]-'A');
            c++;
        }
        else a.push_back('\0');
        
        if(i==l){
            i=1;
            l=c*2;
            c=0;
        }
    }

    string level="";
    Node* root=insertLevelOrder(a,0,a.size());
    levelOrder(root,level);
    cout<<endl<<"levelorder : "<<level<<endl;
    return 0;
}