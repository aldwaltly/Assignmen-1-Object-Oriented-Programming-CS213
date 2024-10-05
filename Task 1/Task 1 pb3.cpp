// File: A1_T1_SectionNum_StudentID.cpp
 // Purpose: to split string by delimiter and put the elements in vector
 // Author: Youssef Mohamed
 // Section: .....................
 // ID: 20230511
 // TA: ...................
 // Date: 29 Sept 2024
 // Detailed explanation of the file and how program works …

#include<bits/stdc++.h>

using namespace std;


vector<string> split(string target,string delimiter){
    vector<string> result;
    int index=0;
    int z=0;
    int size=delimiter.size();
    for(int i = 0 ;i<target.size();i++){
        if(target[i]==delimiter[0]){
            string test(target.begin()+i,target.begin()+i+size);
            if(test==delimiter){
                string sub(target.begin()+index,target.begin()+i);
                result.push_back(sub);
                index=i+size;
                z=i;
            }
        }
    }
    if(z!=target.size()){
        string x(target.begin()+z+delimiter.size(),target.end());
        result.push_back(x);
    }else result.push_back("");
    return result;
}


void menu_3(){
    int n=0;
    cout<<"Welcome to the String splitter"<<endl;
    while(true){
        n=0;
        while(n!=1 && n!=2){
            cout<<"1)split new sentence \n2)Exit\nPlease enter valid choice: ";
            cin>>n;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        if(n==1){
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Enter the target: ";
            string t;getline(cin,t);
            cout<<"Enter the delimiter: ";
            string d;getline(cin,d);
            vector<string> test=split(t,d);
            cout<<"[";
            for(int i = 0 ; i<test.size();i++){
                cout<<"\""<<test[i]<<"\"";
                if(i!=test.size()-1)cout<<",";
            }
            cout<<"]"<<endl;

        }
        else {
            cout << "Exiting the program." << endl;
            return;
        }
    }
}


int main(){
 
    menu_3();
}