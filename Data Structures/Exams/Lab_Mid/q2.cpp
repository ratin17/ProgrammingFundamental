#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int a,b;
    cin>>a;
    int arr1[a];
    for(int i=0;i<a;i++)cin>>arr1[i];
    cin>>b;
    int arr2[b];
    for(int i=0;i<b;i++)cin>>arr2[i];
 
    for(int i=0;i<a;i++){
        bool found=false;
 
        for(int j=0;j<b;j++){
            if(arr1[i]==arr2[j]){
                found=true;
                break;
            }
        }
        if(!found)cout<<arr1[i]<<" ";
 
 
    }
 
    return 0;
}
