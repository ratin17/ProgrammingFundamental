#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int p, int q, int r){
    
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = (l + (r - l)) / 2;
       mergeSort(arr, l, m);
       mergeSort(arr, m+1, r);


       merge(arr,l,m,r);

    }

}





int main(){
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);


    return 0;
}