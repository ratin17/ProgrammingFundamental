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
    int j=0;
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
        
        cout<<endl<<"Step # "<<j<<" : "<<endl;
        cout<<"Status of Stack : ";
        t.show();
        cout<<"Current Prefix String : "<<result<<endl;
        j++;
    }

    while(!t.empty()){
        result+=t.top();
        t.pop();
        cout<<endl<<"Step # "<<j<<" : "<<endl;
        cout<<"Status of Stack : ";
        t.show();
        cout<<"Current Prefix String : "<<result<<endl;
        j++;
    }

    reverse(result.begin(),result.end());

    return result;
}


string infixToPostfix(string s){
    int j=0;
    Stack<char> t;
    string result="";

    for(int i=0;i<s.length();i++){

        if(s[i]>='0'&&s[i]<='9'){
            result+=s[i];
        }
        else if(s[i]=='('){
            t.push(s[i]);
        }
        else if(s[i]==')'){
            while(!t.empty() && t.top()!='('){
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

        cout<<endl<<"Step # "<<j<<" : "<<endl;
        cout<<"Status of Stack : ";
        t.show();
        cout<<"Current Postfix String : "<<result<<endl;
        j++;
    }

    while(!t.empty()){
        result+=t.top();
        t.pop();
        cout<<endl<<"Step # "<<j<<" : "<<endl;
        cout<<"Status of Stack : ";
        t.show();
        cout<<"Current Postfix String : "<<result<<endl;
        j++;
    }

    return result;
}


int evaluatePrefix(string s){
    int j=0;
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
        cout<<endl<<"Step # "<<j<<" : "<<endl;
        cout<<"Status of Stack : ";
        p.show();
        j++;
    }

    return p.top();
}


int evaluatePostfix(string s){
    int j=0;
    Stack<int> p;

    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            p.push((s[i]-'0'));
        }
        else{
            int a=p.top();
            p.pop();
            int b=p.top();
            p.pop();

            if(s[i]=='+')p.push(a+b);
            else if(s[i]=='-')p.push(b-a);
            else if(s[i]=='*')p.push(a*b);
            else if(s[i]=='/')p.push(b/a);
            else if(s[i]=='^')p.push(pow(b,a));
        }
        cout<<endl<<"Step # "<<j<<" : "<<endl;
        cout<<"Status of Stack : ";
        p.show();
        j++;
    }

    return p.top();
}



int main(){
    string in="(5*((6^2)+(7-(2/6))))-((7*(8+1))+(5*4))";
    
    //cin>>in;


    // string pre=infixToPrefix(in);
    
    // cout<<endl<<"Infix String: "<<in<<endl;
    // cout<<"Final Prefix : "<<pre<<endl<<endl;

    // int ans=evaluatePrefix(pre);
    // cout<<"Evaluation in prefix : "<<ans<<endl;



    string post=infixToPostfix(in);
    
    cout<<"Infix : "<<in<<endl;
    cout<<"Postfix : "<<post<<endl;

    int ans=evaluatePostfix(post);
    cout<<"Evaluation in Postfix : "<<ans<<endl;


    return 0;
}

// 