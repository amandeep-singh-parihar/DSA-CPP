#include <bits/stdc++.h>
using namespace std;

string toTitleCase(string s) {
    stringstream ss(s);
    string word, result = "";
    bool firstWord = true;
    
    while (ss >> word) {
        bool isAcronym = all_of(word.begin(), word.end(), ::isupper);
        
        if (!isAcronym) {
            word[0] = toupper(word[0]);
            for (int i = 1; i < word.length(); ++i) {
                word[i] = tolower(word[i]);
            }
        }

        if (firstWord) {
            result += word;
            firstWord = false;
        } else {
            result += " " + word;
        }
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string S;
        getline(cin, S);
        
        cout << toTitleCase(S) << endl;
    }

    return 0;
}
