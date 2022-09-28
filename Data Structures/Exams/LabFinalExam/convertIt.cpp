#include<bits/stdc++.h>
using namespace std;


int main(){
    int l=1;
    int n,a,b;
    int p,c=0;
    priority_queue<int>pq;
    for(int i=1;i<=l;i++){
        cin>>p;
        if(p!=-1){
            pq.push(p);
            c++;
        }
        
        if(i==l){
            i=0;
            l=c*2;
            c=0;
        }
    }

    cin>>n;
    //cout<<"n==: "<<n<<endl;
    while(n--){
        cin>>a;
        if(a==1){
            cin>>b;
            pq.push(b);
        }
        if(a==2){
            cout<<pq.top()<<endl;
            pq.pop();
        }
    }

    
    
    return 0;
}
