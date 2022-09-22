#include <bits/stdc++.h>
using namespace std;

int main(){
    long t;
    cin>>t;
    while(t--){
        long n,c,z,s=0;
        cin>>n>>c;
        for(long i=0;i<n;i++){
            cin>>z;
            s+=2*z;
        }
        if(s<=c)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}