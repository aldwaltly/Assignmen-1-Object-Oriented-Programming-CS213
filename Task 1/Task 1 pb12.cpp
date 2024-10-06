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






int main() {
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
    if (n == 2)return 0;
 
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


