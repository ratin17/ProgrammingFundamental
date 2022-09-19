#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin>>n;
    int m;
    if(n%2==0)m=n+1;
    else m=n;
    int p=m;

    int s=m/2;
    int t=s;

    for(int i=1;s>=1;s--,i=i+2){
        for(int j=0;j<s;j++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int j=0;j<p;j++){
        cout<<"*";
    }
    cout<<endl;

    p=p-2;
    s=1;

    for(;p>0;p=p-2,s++){
        for(int j=0;j<s;j++){
            cout<<" ";
        }
        for(int j=0;j<p;j++){
            cout<<"*";
        }
        cout<<endl;
    }



    return 0;
}
