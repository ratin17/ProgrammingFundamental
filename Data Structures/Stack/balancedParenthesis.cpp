#include<bits/stdc++.h>
#include "MyStack.h"

using namespace std;

char getPartner(char c){
    if(c==')')return '(';
    if(c=='}')return '{';
    if(c==']')return '[';
    else return '\0';
}

bool isBalanced(string s){
    Stack<char> p;

    for(int i=0;i<s.length();i++){

        if(s[i]=='(' || s[i]=='{' || s[i]=='[')p.push(s[i]);

        else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(p.empty())return false;
            else if(p.top()==getPartner(s[i]))p.pop();
            else{
                return false;
            }
        }
    }
    if(!p.empty()) return false;
    else return true;
}

int main(){
    string s;
    cin>>s;

    if(isBalanced(s))cout<<"Parenthesises are balanced !"<<endl;
    else cout<<"Parenthesises are not balanced !"<<endl;

    return 0;
}