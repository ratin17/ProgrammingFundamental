#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        stack<char>p;
        stack<char>q;

        int n;
        cin>>n;
        
        while(n--){
            char c,a,b;
            cin>>a;
        
            if(!p.empty()){
                b=p.top();

                if(a==b)p.pop();

                else if((a=='R' && b=='B')||(a=='B' && b=='R')){
                    p.pop();
                    if(!p.empty() && p.top()=='P')p.pop();
                    else p.push('P');
                }

                else if((a=='R' && b=='G')||(a=='G' && b=='R')){
                    p.pop();
                    if(!p.empty() && p.top()=='Y')p.pop();
                    else p.push('Y');
                }

                else if((a=='B' && b=='G')||(a=='G' && b=='B')){
                    p.pop();
                    if(!p.empty() && p.top()=='C')p.pop();
                    else p.push('C');
                }

                else p.push(a);
            }
            else p.push(a);
            
            //cout<<"p top:"<<p.top()<<endl;
        }
        
        while(!p.empty()){
            q.push(p.top());
            p.pop();
        }

        while(!q.empty()){
            cout<<q.top();
            q.pop();
        }
        cout<<endl;

    }
    return 0;
}