#include <bits/stdc++.h>
#include "MyStack.h"

using namespace std;

int main() {
    bool b;
    int i;
    Stack<int> s;

    b=s.empty();
    s.push(6);
    b=s.empty();
    s.pop();
    b=s.empty();
    s.push(62);
    s.push(66);
    s.pop();
    b=s.empty();
    s.pop();
    b=s.empty();

    return 0;
}
