#include <iostream>
using namespace std;

int main(){ 
  int x;
  cin>>x;
  
  int mid = x/2;
  int min = 0;
  int max = x-1;
  
  int arr[x][x];
  for(int i = 0; i < x; i++){
    for(int j = 0; j < x; j++){
      cin>>arr[i][j];
    }
  }
  
  int result = 0;
  for(int i = 0; i < x; i++){
    for(int j = 0; j < x; j++){
      if(
      ( i == mid ) || 
      ( j == mid ) ||
      ( j < mid && i == min ) ||
      ( j > mid && i == max ) ||
      ( i > mid && j == min ) ||
      ( i < mid && j == max )
      ){
        result += arr[i][j];
      }
    }
  }
  
  cout<<result<<endl;
  
  return 0;
}
