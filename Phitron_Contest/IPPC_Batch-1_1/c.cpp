#include<bits/stdc++.h>
using namespace std;

int main(){
    long n;
    cin>>n;
    long a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    long j=n-1;
    for(;j>-1;j--){
        cout<<a[j]<<" ";
    }

    return 0;
}

