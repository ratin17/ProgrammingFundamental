
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
vector<int>g[N];



int main(){
    int n=5,inp;
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>inp;
            if(inp==1){
                g[i].push_back(j);
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<i<<" ->";
        for(auto adj:g[i]){
            cout<<" "<<adj;
        }
        cout<<endl;
    }
    

    return 0;
}


/*
Input:

7 7
1 3
3 4
3 5
5 6
4 2
4 7
2 7


*/