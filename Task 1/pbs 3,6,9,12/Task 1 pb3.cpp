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
    int size=delimiter.size();
    for(int i = 0 ;i<target.size();i++){
        if(target[i]==delimiter[0]){
            string test(target.begin()+i,target.begin()+i+size);
            if(test==delimiter){
                string sub(target.begin()+index,target.begin()+i);
                result.push_back(sub);
                index=i+size;
            }
        }
    }
    return result;
}


int main(){

    string target="10,,20,,30,,40,,50";

    vector<string> test=split(target,",,");
    for(int i = 0 ; i<test.size();i++){
        cout<<test[i]<<endl;
    }

}