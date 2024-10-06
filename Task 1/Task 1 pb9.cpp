// File: ……….cpp
// Purpose: ………
// Author: .....................
// Section: .....................
// ID: .....................
// TA: ...................
// Date: 30 Sept 2024
// Detailed explanation of the file and how program works …



#include<bits/stdc++.h>

using namespace std;


bool bears(int n){
    bool x=false;
    if(n>42){
        if(n%2==0){
            x=bears(n/2);
        }
        if((n%4==0 || n%3==0) && !x && ((n%10)*((n%100)/10))!=0){
            x=bears(n-((n%10)*((n%100)/10)));
        }
        if(n%5==0 && !x){
            x=bears(n-42);
        }

        if(x)return true;
        else return false;
    }
    else if(n==42)return true;
    else return false;
}

void menu9(){
    cout<<"Welcome to tiddy Bears picnic"<<endl;
    int x=0;
    while(x!=1 && x!=2){
        cout<<"1)Test new number\n2)Exit\nPlease eneter valid choise: ";cin>>x;
    }
    if(x==2)return;
    else{
        int n=0;
        while(true){
            cout<<"Please enter the new number you'd like to test in the Bear's Game: ";cin>>n;
            if(cin.fail()){
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else break;
        }
        if(bears(n))cout<<"You can win with this score! Keep going!"<<endl;
        else cout<<"You can't win with this score"<<endl;
    }
}


int main(){
    menu9();

}