#include <iostream>
using namespace std;

int main() 
{ 
  int x, y;
  cin>>x>>y;
  int check[x*y];
  for(int i = 0; i < x*y; i++){
    check[i] = -1;
  }
  int givenArray[x][y];
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      cin>>givenArray[i][j];
    }
  }
  int count = 0;
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      count++;
      if(count == 1){
        check[count-1] = givenArray[i][j];
      }else{
        int flag = 0;
        for(int k = 0; k < count-1; k++){
          if( givenArray[i][j] == check[k]){
            flag = 1;
          }
        }
        if(flag == 0){
          check[count-1] = givenArray[i][j];
        }
      }
    }
  }
  for(int i = 0; i < x*y; i++){
    cout<<check[i];  
    if((i+1)%y == 0){
      cout<<endl;
    }else{
      cout<<" ";
    }
  }
  cout<<endl;
  return 0;
}
