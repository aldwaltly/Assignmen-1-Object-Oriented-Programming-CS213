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

void menu6(){
     cout<<"Binary Printer and Sequence Generator"<<endl;
   int n=0;
    while(n!=1 && n!=2 && n!=3){
        cout<<"1)Binary Printer \n2)Sequence Genrator\n3)Exit\nPlease enter valid choice: ";
        cin>>n;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    if(n==3)return;
    else if(n==1){
        int x=-1;
        while(x<0){
            cout<<"Could you please provide a number you'd like to convert to binary? \"The number must be >=0\" ";
            cin>>x;
        }
        if(n==0)cout<<0<<endl;
        else {
            binaryPrint(x);
            cout<<endl;
        }
    }
    else{
        string x;
        while(true){
            cout<<"Could you please enter the binary number you'd like to use to create a sequence? ";cin>>x;
            bool z=1;
            for (int i = 0; i < x.size(); i++) {
                if (x[i] != '0' && x[i] != '1') {
                    z = 0;
                    break;
                }
            }
            if(z)break;
        }
        int f=-1;
        while(f<0){
            cout<<"Could you please provide the number you'd like to add to the binary code to create a sequence? ";cin>>f;
        }
        if(f==0)cout<<x<<endl;
        else numbers(x,f);
    }


}

int main(){
   
menu6();
}

