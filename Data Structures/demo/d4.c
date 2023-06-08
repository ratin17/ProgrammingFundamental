#include<stdio.h>
#include<string.h>
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    long long int arr[n];

    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }

    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n;j++){
    //         if(arr[i]<arr[j]){
    //             long long int t=arr[i];
    //             arr[i]=arr[j];
    //             arr[j]=t;
    //         }
    //     }
    // }

    for(int i=0;i<n;i++){
        printf("%lld ",arr[i]);
    }
    printf("\n");


    return 0;
}

/*

6 4
6 9 0 -1 5 6

*/