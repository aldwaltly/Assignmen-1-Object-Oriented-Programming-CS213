#include <iostream>
#include <string>

using namespace std;

string correctSentence(string sentence) {

    string result;
    bool spaceFound = false;

    for (char ch : sentence) {
        if (isspace(ch)) {
            if (!spaceFound) {
                result += ' ';
                spaceFound = true;
            }
        } else {
            result += tolower(ch);
            spaceFound = false;
        }
    }

    if (!result.empty()) {
        result[0] = toupper(result[0]);
    }
    
    if (result.back() != '.') {
        result += '.';
    }

    return result;
}

int main() {
    string input;
    cout << "Enter a sentence (max 100 characters): ";
    getline(cin, input);

    string corrected = correctSentence(input);
    cout << "Corrected sentence: " << corrected << endl;

    return 0;
}
