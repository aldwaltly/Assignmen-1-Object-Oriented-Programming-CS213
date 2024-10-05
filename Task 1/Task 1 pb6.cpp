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

    if(n>=1){
        binaryPrint(n>>1);
        cout<<(n&1);
    }
    else if(n<0){
        cout<<"error input";
    }

}


void numbers(string prefix, int k){
        bool x=false;
        string result1;
        string result2;
        bool z=0;
        if(k>0){
            z=1;
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
    while(true){
        string x;cin>>x;
        int c;cin>>c;
        bool z = 1;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != '0' && x[i] != '1') {
                z = 0;
                break;
            }
        }
        if(z){
            if(c==0){
                cout<<x<<endl;
            }
            numbers(x,c);
        }
        else{
            cout<<"error"<<endl;
        }
    }

}