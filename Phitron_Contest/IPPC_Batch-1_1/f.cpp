#include<bits/stdc++.h>
using namespace std;

// function to find out the maximum repeating
// character in given string
int maxRepeating(string str)
{
    int len = str.length();
    int count = 0;

    char res = str[0];
    for (int i=0; i<len; i++)
    {
        int cur_count = 1;
        for (int j=i+1; j<len; j++)
        {
            if (str[i] != str[j])
                break;
            cur_count++;
        }

        if (cur_count > count)
        {
            count = cur_count;
            res = str[i];
        }
    }
    return count;
}

// Driver code
int main()
{
    int n;
    cin>>n;

    string str;
    cin>>str;
    cout << maxRepeating(str);
    return 0;
}
