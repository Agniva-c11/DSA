#include <iostream>
#include <string>
using namespace std;

char getMaxOccurringChar(const string& str) {
    int maxCount = 0;
    char maxChar = '\0';

    for (int i = 0; i < str.length(); i++) {
        int count = 0;
        for (int j = 0; j < str.length(); j++) {
            if (str[i] == str[j])
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            maxChar = str[i];
        }
    }

    return maxChar;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    char result = getMaxOccurringChar(input);
    cout << "Maximum occurring character: " << result << endl;

    return 0;
}
