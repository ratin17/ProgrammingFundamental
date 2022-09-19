
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> v;
    int w;
    for(int i=0;i<n;i++){
        cin>>w;
        v.push_back(w);
    }
    sort(v.begin(), v.end());

    cout<<v[0]+v[1]<<endl;




    return 0;
}

