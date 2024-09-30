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

    vector<string> phishingKeywords = {
         "urgent", "account suspended", "verify your account", "update your information",
         "limited-time offer", "password expired", "click here", "congratulations",
         "free gift", "confirm your identity", "bank", "credit card",
         "social security number", "paypal", "unusual activity", "login to your account",
         "suspicious activity", "action required", "reset password",
         "your account has been compromised", "act now", "personal information",
         "immediate attention", "verify now", "security alert",
         "your funds are on hold", "important notice", "you've won",
         "payment declined", "secure your account"
    };

    ifstream file1("Test.txt");
    string line;
    int count = 0;
    while (getline(file1, line)) {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        for (auto keyword : phishingKeywords) {
            if  (line.find(keyword) != string::npos) {
                count++;
            }
        }

    }
    cout << count << endl;
    if (count >= 4)cout << "Fake" << endl;
    else cout << "Real" << endl;
}


