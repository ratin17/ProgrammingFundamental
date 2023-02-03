#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin>>N;
   int count = 0;
    for (int i = N; i > 0; i /= 2) {
        for (int j = 0; j < i; j++) {
            count += 1;
        }
    }
    cout<<count<<endl;
   return 0;
}
