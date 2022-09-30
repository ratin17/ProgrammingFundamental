#include <bits/stdc++.h>
#include "Ratin_Stack.h"

using namespace std;

int main() {
    bool b;
    int i;
    Stack<int> s;

    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    cout<<s.mid()<<endl;
    return 0;
}
