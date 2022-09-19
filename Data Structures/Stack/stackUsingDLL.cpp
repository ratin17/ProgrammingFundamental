#include <bits/stdc++.h>
#include "MyStack.h"

using namespace std;

int main() {
    bool b;
    int i;
    Stack s;

    b=s.empty();
    s.push(6);
    b=s.empty();
    i=s.pop();
    b=s.empty();
    s.push(62);
    s.push(66);
    i=s.pop();
    b=s.empty();
    i=s.pop();
    b=s.empty();

    return 0;
}
