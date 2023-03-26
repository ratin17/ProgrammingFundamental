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


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(i==j&&g[i][j]!=0){
                cout<<"NO"<<endl;
                return 0;
            }

            if(g[i][j]!=0 && g[j][i]==0){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;

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