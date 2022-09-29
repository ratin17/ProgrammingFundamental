#include<bits/stdc++.h>

using namespace std;
 


struct Node
{
    char data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};


bool isPalindrome(vector<char> str){
    int l = 0;
    int h = str.size() - 1;
    
    while (h > l){
        if (str[l++] != str[h--])return false;
        
    }
    return true;
}


bool isLeaf(Node* node) {
    return (node->left == nullptr && node->right == nullptr);
}
 
int c=0;
void printRootToLeafPaths(Node* node, vector<int> &path)
{
    
    if (node == nullptr) {
        return;
    }
 
    
    path.push_back(node->data);
 
    
    if (isLeaf(node)){
        vector<char> chk;
        for (int data: path) {
            chk.push_back(data);
        }
        if(isPalindrome(chk))c++;
    }
 
    
    printRootToLeafPaths(node->left, path);
    printRootToLeafPaths(node->right, path);
 
    
    path.pop_back();
}
 
void printRootToLeafPaths(Node* node){
    vector<int> path;
    printRootToLeafPaths(node, path);
}
 
int main()
{
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

    printRootToLeafPaths(root);
    cout<<c<<endl;
}
