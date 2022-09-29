#include<bits/stdc++.h>
using namespace std;


int main(){
    int m,n;
    cin>>m>>n;
    int arr1[m][n];
    int arr2[m*n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
            arr2[i*(n-1)+j]=arr1[i][j];
        }
    }

    for(int i=0;i<m*n;i++)cout<<arr2[i]<<" ";
    cout<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            bool found = false;
           for(int k=0;k<(i*(n-1)+j)-1;k++){
                if(arr1[i][j]==arr2[k]){
                    found=true;
                    cout<<"("<<i<<" "<<j<<" "<<k<<" "<<
                    arr2[k]<<") ";

                    break;
                }
           }
           if(!found)cout<<arr1[i][j]<<" ";
           else cout<<-1<<" "; 
        }
        cout<<endl;
    }

    return 0;
}