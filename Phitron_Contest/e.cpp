#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,a,b,q,r=0;
    cin>>n>>m;
    int p[n+1][n+1]={0};
    while(m--){
        r=0;
        cin>>a>>b;
        a<b?p[a][b]=1:p[b][a]=1;
        p[a][0]=1;
        p[b][0]=1;
    }
    cin>>q;
    int x,y,z;
    while(q--){
        cin>>x;

        if(x==3){
            r=0;
            for(int i=1;i<=n;i++){
                if(p[i][0]==1){
                    for(int j=i+1;j<=n;j++){
                        if(p[i][j]==1){
                            //cout<<"Caught: "<<i<<endl;
                            p[i][j]=0;
                            p[i][0]=0;
                        }
                    }
                }
            }

            for(int i=1;i<=n;i++){
                //cout<<p[i][0]<<endl;
                if(p[i][0]==1){
                     r++;
                }
            }
            cout<<r<<endl;
        }
        if(x==1){
            cin>>y>>z;
            y<z?p[y][z]=1:p[z][y]=1;
            p[y][0]=1;
            p[z][0]=1;

        }
        if(x==2){
            cin>>y>>z;
            y<z?p[y][z]=0:p[z][y]=0;
        }
    }
    return 0;
}
