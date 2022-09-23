#include<bits/stdc++.h>
#include "MYQUEUE.h"

using namespace std;

int main(){

    Queue q;
    q.push(8);
    q.push(7);
    q.push(7);
    q.pop();
    q.push(3);
    //q.show();

    queue<int> j;

    j.push(1);
    cout<<"val: "<<j.front()<<endl;

    j.pop();
    cout<<"val: "<<j.front()<<endl;

    j.push(7);
    cout<<"val: "<<j.front()<<endl;

    j.pop();
    cout<<"val: "<<j.front()<<endl;

    
    cout<<"0 : Exit"<<endl;
    cout<<"1 : Show Current Queue"<<endl;
    cout<<"2 : Push"<<endl;
    cout<<"3 : Pop"<<endl;
    cout<<"4 : Show Front"<<endl;
    cout<<"5 : Show Back"<<endl;
    cout<<"6 : Check Empty"<<endl;
    
    int c=1,v,p,k;
    while(c!=0){
        cout<<endl<<"Enter choice:";
        cin>>c;

        if(c==1)q.show();

        else if(c==2){
            cout<<"Enter Value to push :";
            cin>>v;
            q.push(v);
        }
        else if(c==3){
            cout<<endl<<"Pop Value : "<<q.pop()<<endl;
        }
        else if(c==4){
            cout<<endl<<"Front Value : "<<q.getFront()<<endl;
        }
        else if(c==5){
            cout<<endl<<"Back Value : "<<q.getBack()<<endl;
        }
        else if(c==6){
            if(q.empty())cout<<"Queue is Empty !"<<endl;
            else cout<<"Queue is not Empty !"<<endl;
        }

        

    }


    return 0;
}