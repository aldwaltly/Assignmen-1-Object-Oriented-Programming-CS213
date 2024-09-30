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



int mian(){

    cout<<bears(52);

}