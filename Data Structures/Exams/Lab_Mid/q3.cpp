#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        int ar1[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar1[i];
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int st;
            cin >> st;
            int TE = 0;
            int TS = 0;
            if (st == 0)
            {
                TE = ar[0];
                TS = ar1[0];
            }
            else
            {
                for (int j = 0; j <= st; j++)
                {
                    TE += ar[j];
                    TS += ar1[j];
                }
            }
            if (TE - TS < 0)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
    }
}