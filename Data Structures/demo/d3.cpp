#include <bits/stdc++.h>
using namespace std;


vector<int> mergesort(vector<int> a)
{

    if (a.size() <= 1)
    {
        return a;
    }

    int mid = a.size() / 2;
    vector<int> b;
    vector<int> c;

    for (int i = 0; i < mid; i++)
    {
         cout<<a[i]<<" ";
        b.push_back(a[i]);
    }
   cout<<"\n";


    for (int i = mid; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
        c.push_back(a[i]);
    }
    cout<<"\n";


     for (int i = 0; i < mid; i++)
    {
       cout<<b[i]<<" ";
    }
    cout<<"\n";

    
    for (int i = mid; i <a.size() ; i++)
    {
        
        cout<<c[i]<<" ";
    }
}

int main()
{

    vector<int> a = {7, 5, 3, 2, 1, 4, 6, 8};
    vector<int> asn = mergesort(a);
}