#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1e3;
int const INF=1e5;
int g[N][N];





int main(){
    int n;
    cin>>n;

    int s=0,a;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a;
            s+=a;
        }
    }

    cout<<s/2<<endl;

    return 0;
}

/*
Input

-------------------

4 3
1 2 5
1 3 9
2 3 3

-------------------


*/