#include<bits/stdc++.h>
using namespace std;

const int N = 1009;
const int M = 1e5 + 5;

int wt[N], val[N];

long long Knapsack(int idx, int W){

    if (idx == 0) {
        return (W / wt[0]) * val[0];
        //return 0;
    }
    
    int ans1=Knapsack(idx - 1,W);
   
    int ans2 =INT_MIN;
    if (wt[idx] <= W){
        ans2 = val[idx]+ Knapsack(idx,W - wt[idx]);
    }
    return max(ans1,ans2);
}
 

int main(){
   long long n, cap;
    cin >> n >> cap;

    for(int i = 0 ; i < n ; i++) {
        cin >>val[i];
    }

    for(int i = 0 ; i < n ; i++) {
        cin >> wt[i];
    }
 
    cout<<Knapsack(n,cap)<<endl;
 
    return 0;
}