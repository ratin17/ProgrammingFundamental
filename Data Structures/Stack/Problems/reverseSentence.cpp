#include<bits/stdc++.h>
#include "MyStack.h"

using namespace std;

int main(){
    string s;
    getline(cin,s);

    Stack<string>st;
    string word="";

    for(int i=0;i<s.length();i++){
        if(s[i]==' ' ){
            st.push(word);
            word="";
        }
        else word+=s[i];
    }
    st.push(word);

    int i=0;
    string reversed[100];
    while(!st.empty()){
        reversed[i]=st.top();
        st.pop();
        i++;
    }

    for(int i=0;i<reversed->length();i++){
        cout<<reversed[i]<<" ";
    }

    return 0;

}