#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        int f=0,c=0;
        vector <int>v;
        cin>>s;

        for(int i=0;i<s.length();i++){
            if(f==0){
                if(s[i]=='1'){
                    c++;
                    f=1;
                }
            }
            else{
                if(s[i]=='1')c++;
                else{
                    //cout<<c<<" ";
                    v.push_back(c);
                    c=0;
                    f=0;
                }

            }
        }
        if(f)v.push_back(c);
        /*
        cout<<endl;

        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        */
        sort(v.begin(),v.end(),greater <>());
        int a=0;
        for(int i=0;i<v.size();i=i+2)a+=v[i];

        cout<<a<<endl;

    }
    return 0;
}
