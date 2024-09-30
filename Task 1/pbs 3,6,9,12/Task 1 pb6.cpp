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



void binaryPrint(int n) {

    if(n>1){
        binaryPrint(n>>1);

    }
    cout<<(n&1);

}


void numbers(string prefix, int k){
        bool x=false;
        string result1;
        string result2;
        if(k>0){
            result1=prefix+'0';
            result2=prefix+'1';
            numbers(result1,k-1);
            numbers(result2,k-1);
            x=true;
            if(x &&  k==1){
            cout<<result1<<endl;
            }
            if(x &&  k==1){
            cout<<result2<<endl;
            }
        }

}

int main(){

}