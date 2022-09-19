#include <bits/stdc++.h>
using namespace std;

class Matrix{
    public:
    int row,col;
    int mat[99][99];

    Matrix(int r,int c){
        row=r;
        col=c;
    }

    void setMatrix(){
        cout<<"Enter values for "<<row<<"X"<<col<<" Matrix:"<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>mat[i][j];
            }
        }
    }

    void printMatrix(){
        cout<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }


};

Matrix multiplyMatrix(Matrix p,Matrix q){
        cout<<"Resulting Matrix :"<<endl;
        Matrix r(p.row,q.col);
        for(int i=0;i<p.row;i++){
            for(int x=0;x<q.col;x++){
                int sum=0;
                for(int j=0;j<p.col;j++){
                    sum+=p.mat[i][j]*q.mat[j][x];
                }
                r.mat[i][x]=sum;
            }
        }
        return r;
}


int main(){
    int r,c;

    cout<<"Enter the number of rows and cols for 1st Matrix:";
    cin>>r>>c;
    Matrix A=Matrix(r,c);
    A.setMatrix();
    A.printMatrix();

    cout<<"Enter the number of rows and cols for 2nd Matrix:";
    cin>>r>>c;
    Matrix B=Matrix(r,c);
    B.setMatrix();
    B.printMatrix();

    Matrix D=multiplyMatrix(A,B);
    D.printMatrix();

    return 0;
}




/*

1 0 1
2 1 1
0 1 1
1 1 2

1 2 1
2 3 1
4 2 2

*/

