#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int fib(int n){
    if(n==0)return 0;
    if(n==1)return 1;

    int a=fib(n-1),b=fib(n-2);
    
    return a+b;
}

int main() {
    cout<<fib(4)<<endl;
   
}

