#include <bits/stdc++.h>
using namespace std;


string isPalindrome(string S)
{

    string P = S;

    reverse(P.begin(), P.end());

    if (S == P) {
        // Return "Yes"
        return "YES";
    }
    // Otherwise
    else {
        // return "No"
        return "NO";
    }
}

// Driver Code
int main()
{
    string S;
    long n;
    cin>>n;
    cin>>S;
    cout << isPalindrome(S);

    return 0;
}
