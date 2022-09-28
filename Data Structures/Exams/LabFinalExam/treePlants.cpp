#include <bits/stdc++.h>
using namespace std;

int main(){
    long long y = 0;
    cin>>y;
    if(y == 1){
        cout<<1<<endl;
    }
    else{
      long long ans = pow(2,y-1)*pow(2,y-2);
        cout<<ans<<endl;
    }
    return 0;
}