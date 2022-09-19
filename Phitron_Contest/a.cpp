#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin>>t;
    while(t--){
        long long x,a=0;
        cin>>x;
        if(x<60){
            a+=60-x;
            x=60;
        }
        if(x<80){
            a+=(80-x)*2;
            x=80;
        }
        if(x<100){
            a+=(100-x)*3;
        }
        cout<<a<<" minutes"<<endl;
    }
    return 0;
}
