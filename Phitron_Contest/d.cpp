#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,a;
        cin>>n;
        a=floor(log2(n));
        if((n+1)==(pow(2,a+1)))a++;

        cout<<a<<endl;
    }
    return 0;
}
