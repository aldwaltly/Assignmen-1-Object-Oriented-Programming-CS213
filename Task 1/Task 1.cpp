// File: ……….cpp
// Purpose: ………
// Author: .....................
// Section: .....................
// ID: 20230511
// TA: ...................
// Date: 31 Sept 2024
// Detailed explanation of the file and how program works …



#include<bits/stdc++.h>
#include<algorithm>
#include<fstream>
#include <sstream>
using namespace std;



void menu12(){
    vector<pair<string, int>> phishingKeywords = {
        {"urgent", 2}, {"account suspended", 2}, {"verify your account", 2}, {"update your information", 1},
        {"limited-time offer", 3}, {"password expired", 2}, {"click here", 3}, {"congratulations", 1},
        {"free gift", 1}, {"confirm your identity", 2}, {"bank", 2}, {"credit card", 2},
        {"social security number", 3}, {"paypal", 2}, {"unusual activity", 2}, {"login to your account", 2},
        {"suspicious activity", 2}, {"action required", 2}, {"reset password", 2},
        {"your account has been compromised", 3}, {"act now", 3}, {"personal information", 2},
        {"immediate attention", 2}, {"verify now", 2}, {"security alert", 2},
        {"your funds are on hold", 3}, {"important notice", 2}, {"you've won", 1},
        {"payment declined", 2}, {"secure your account", 2}
    };

    string i;
    cout << "Welcome to PhishGuard" << endl;
    int n = 0;
    while (n != 1 && n != 2) {
        cout << "1)check new message\n2)Exit\nPlease enter valid choise: "; cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    bool zz = true;
    if (n == 2)return;
 
    else {
        while (true) {
            cout << "Please enter your .txt file: ";
            if(zz)cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, i);
            fstream ii(i);
            if (ii)break;
            else {
                zz = false;
                cout << "cant open the file try again" << endl;
            }
        }
        fstream file1(i);
        string line;
        int count = 0;
        vector<pair<string, int>> nkey;
        while (getline(file1, line)) {
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            for (int i = 0; i < phishingKeywords.size(); i++) {
                if (line.find(phishingKeywords[i].first) != string::npos) {
                    nkey.push_back(phishingKeywords[i]);

                }
            }

        }
        count = 1;
        int sum = 0;
        sort(nkey.begin(), nkey.end());
        cout << "The report is ready please enter the output file name with the extension .txt: "; 
        while (true) {
            getline(cin, i);
            int fa = i.size();
            if (i.substr(fa-4)==".txt")break;
            else {
                cout << "please enter valid extension .txt: ";

            }
        }
        ofstream out(i);
        if (!nkey.empty() && nkey.size() != 1) {
            out << left << setw(40) << "Phishing Keywords and Points" << endl;
            out << string(60, '-') << endl;
            for (int i = 1; i < nkey.size(); i++) {
                if (nkey[i] == nkey[i - 1]) {
                    count++;
                }
                else {
                    out << left << setw(40) << nkey[i - 1].first << right << setfill(' ') << setw(9) << nkey[i - 1].second << "\t repeated " << count << " Time(s) " << nkey[i - 1].second * count << endl;
                    sum += nkey[i - 1].second * count;
                    count = 1;
                }
            }
            out << "Total points: " << sum << endl;
        }
        if (nkey.size() == 1) {
            out << left << setw(40) << nkey[0].first << right << setfill(' ') << setw(9) << nkey[0].second << "\t repeated " << count << " Time(s) " << nkey[0].second * count << endl;
            out << "Total points: " << sum;
        }
        if (nkey.size() == 0) {
            count = 0;
        }
        out << "The final result: ";
        if (count == 0) {
            out << "it is safe";
        }
        else if (count > 0 && count < 10) {
            out << "it may be a scam";
        }
        else {
            out << "it is definitely a scam";

        }
}
}


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



int main() {

    cout<<"Welcome";
    while(true){
        int n=0;
        while(n!=1 &&n!=2 &&n!=3 &&n!=4 &&n!=5){
            cout<<"1)String splitter\n2)Binary Printer and Sequence Generator\n3)tiddy Bears picnic\n4)PhishGuard\n5)Exit\nPlease enter valid choise: ";cin>>n;
            if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
        }
        if(n==5)return 0;
        if(n==1)menu_3();
        if(n==2)menu6();
        if(n==3)menu9();
        if(n==4)menu12();
    }

}

