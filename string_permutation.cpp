#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false;

    vector<int> count1(26, 0);  // frequency of chars in s1
    vector<int> count2(26, 0);  // frequency in current window of s2

    for (char c : s1) {
        count1[c - 'a']++;
    }

    for (int i = 0; i < s1.length(); i++) {
        count2[s2[i] - 'a']++;
    }

    if (count1 == count2) return true;

    for (int i = s1.length(); i < s2.length(); i++) {
        count2[s2[i] - 'a']++;                            // add new char
        count2[s2[i - s1.length()] - 'a']--;              // remove old char

        if (count1 == count2) return true;
    }

    return false;
}

int main() {
    string s1, s2;
    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    cout << (checkInclusion(s1, s2) ? "true" : "false") << endl;

    return 0;
}
