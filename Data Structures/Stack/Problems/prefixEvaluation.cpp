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
    Stack<char> t;
    reverse(s.begin(),s.end());
    string result="";

    for(int i=0;i<s.length();i++){

        if(s[i]>='0'&&s[i]<='9'){
            result+=s[i];
        }
        else if(s[i]==')'){
            t.push(s[i]);
        }
        else if(s[i]=='('){
            while(!t.empty() && t.top()!=')'){
                result+=t.top();
                t.pop();
            }
            if(!t.empty())t.pop();
        }
        else{
            while(!t.empty() && calcPrec(s[i])<=calcPrec(t.top()) ){
                result+=t.top();
                t.pop();
            }
            t.push(s[i]);
        }
    }

    while(!t.empty()){
        result+=t.top();
        t.pop();
    }

    reverse(result.begin(),result.end());

    return result;
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
    }

    return p.top();
}

int main(){
    string in="(5*((6^2)+(7-(2/6))))-((7*(8+1))+(5*4))";
    //cin>>in;

    string pre=infixToPrefix(in);
    
    cout<<"Infix : "<<in<<endl;
    cout<<"Prefix : "<<pre<<endl;

    int ans=evaluatePrefix(pre);
    cout<<"Evaluation in prefix : "<<ans<<endl;

    return 0;
}

// 