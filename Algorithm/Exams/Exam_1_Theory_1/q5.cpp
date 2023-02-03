
#include <bits/stdc++.h>
using namespace std;

string int_to_binary(int decimal){
   if(decimal<=0)return "";

    char c;
    if(decimal%2==0)c='0';
    else c='1';
    decimal/=2;

    return int_to_binary(decimal)+c;
}


int main(){
    int n=897;
    cout<<int_to_binary(n)<<endl;
    return 0;
}


string Iint_to_binary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        if (decimal % 2 == 0) {
            binary = '0' + binary;
        }
        else {
            binary = '1' + binary;
        }
        decimal /= 2;
    }
    return binary;
}