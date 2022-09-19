#include <bits/stdc++.h>

using namespace std;

//////  Answer to Question Number 1  /////////////////

class Restaurant{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_tax;

//////  Answer to Question Number 2  /////////////////

    void inputFood(){
        int n,codes,prices;
        string names;
        cout<<"How many items you want to Input:";
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>food_item_codes[i];
            //cin>>food_item_names[i];
            cin.ignore();
            getline(cin,food_item_names[i]);
            cin>>food_item_prices[i];
        }
    }

//////  Answer to Question Number 3  /////////////////

    void showItems(){
        cout<<"\n\n\t\t\t Make Bill"<<endl;
        cout<<"___________________________________________________________________________________________"<<endl;
        cout<<"Item Code\t\t\tItem Name\t\t\tItem Price"<<endl;
        cout<<"___________________________________________________________________________________________"<<endl;
        for(int i=0;i<12;i++){
            cout<<food_item_codes[i]<<"\t\t\t"<<food_item_names[i]<<"\t\t\t"<<food_item_prices[i]<<endl;
        }
    }

};


int main() {
    Restaurant myRestaurant;
    myRestaurant.inputFood();
    myRestaurant.showItems();

//////  Answer to Question Number 4  /////////////////

    reorder:
    int table,items;
    cout<<endl<<"\nEnter Table no:";
    cin>>table;
    cout<<"Enter number of Items:";
    cin>>items;

    int price[items],codeI[items],quantityI[items];
    string name[items];

    for(int i=0;i<items;i++){

        again:
            cout<<"Enter Item "<<i+1<<" Code:";
            cin>>codeI[i];
            int flag=0;
            for(int j=0;j<12;j++){

////////////  Answer to Question Number 5  /////////////////

                if(codeI[i]==myRestaurant.food_item_codes[j]){
                    price[i]=myRestaurant.food_item_prices[j];
                    name[i]=myRestaurant.food_item_names[j];
                    flag=1;
                    break;
                }
            }
        if(!flag){

    //////  Answer to Question Number 8  /////////////////

            cout<<"Item code is not valid, Enter again !"<<endl;
            goto again;
        }

        cout<<"Enter Item "<<i+1<<" Quantity:";
        cin>>quantityI[i];
    }

    int subTotal=0,total=0;
    cout<<endl<<endl;
    cout<<"\t\t\t\t\tBill Summary"<<endl;

    cout<<"\nTable No:"<<table<<endl;
    cout<<"______________________________________________________________________________________________________"<<endl;
    cout<<"Item Code\t\tItem Name\t\tItem Price\t\tItem Quantity\t\tTotal Prcice"<<endl;
    cout<<"______________________________________________________________________________________________________"<<endl;

    for(int i=0;i<items;i++){
        subTotal+=price[i]*quantityI[i];
        cout<<codeI[i]<<"\t\t"<<name[i]<<"\t\t"<<price[i]<<"\t\t\t"<<quantityI[i]<<"\t\t\t"<<price[i]*quantityI[i]<<endl;
    }

    //////  Answer to Question Number 6  /////////////////

    myRestaurant.total_tax=(5*subTotal)/100;
    total=total+subTotal+myRestaurant.total_tax;
    cout<<"TAX\t\t\t\t\t\t\t\t\t\t\t\t"<<myRestaurant.total_tax<<endl;
    cout<<"_______________________________________________________________________________________________________"<<endl;

    //////  Answer to Question Number 7  /////////////////

    cout<<"Net Total\t\t\t\t\t\t\t\t\t\t\t"<<total<<endl<<endl;

    goto reorder;

    return 0;
}
