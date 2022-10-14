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

    
    vector<string> reversed;
    while(!st.empty()){
        reversed.push_back(st.top());
        st.pop();
    }


    for(int i=0;i<(reversed.size());i++){
        cout<<reversed[i]<<" ";
    }

    return 0;

}