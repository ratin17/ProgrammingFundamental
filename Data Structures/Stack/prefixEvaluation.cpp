#include<bits/stdc++.h>
#include "MyStack.h"

using namespace std;

int calcPrec(char c);
int evaluatePrefix(string s);
string infixToPrefix(string s);

int calcPrec(char c){
    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='+' || c=='-')return 1;
    else return -1;
}

string infixToPrefix(string s){

}

int evaluatePrefix(string s){
    Stack<int> p;

    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0'&&s[i]<='9'){
            p.push((s[i]-'0'));
        }
        else{
            int a=p.top();
            p.pop();
            int b=p.top();
            p.pop();

            if(s[i]=='+')p.push(a+b);
            else if(s[i]=='-')p.push(a-b);
            else if(s[i]=='*')p.push(a*b);
            else if(s[i]=='/')p.push(a/b);
            else if(s[i]=='^')p.push(pow(a,b));
        }
        p.show();
    }
    return p.top();
}

int main(){
    string s;
    //cin>>s;
    s="+56";
    int ans=evaluatePrefix(s);
    cout<<"Evaluation in prefix : "<<ans<<endl;

    return 0;
}

// 