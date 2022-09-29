#include<bits/stdc++.h>

using namespace std;
 
int main(void){
    int row,col,r,c;
    cin>>row>>col;
    r=row;
    c=col;
    int mat[r][c] = { 0 };
 
    // print the 2D array
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}


