#include <bits/stdc++.h>
using namespace std;
 

void printComb(vector<int> const &out){
    cout<<"{";
    for (int i: out) {
        cout << i << ",";
    }
    cout<<"}"<<endl;
}
 

void Combinations(int i, int n, vector<int>&out){
    
    if (n==0)printComb(out);
 
    for (int j = i; j <= n; j++){
        out.push_back(j);
        Combinations(j, n - j, out);
        out.pop_back();
    }
}
 

int main(){
    int n = 5;
 
    vector<int> out;
 
    Combinations(1, n, out);
 
    return 0;
}