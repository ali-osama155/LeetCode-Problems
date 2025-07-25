#include <iostream>
#include <vector>
#include <string>
using namespace std;

string addSpaces(const string& s, const vector<int>& spaces) {
    string result;
    int spaceIndex = 0;
    int n = spaces.size();

    for (int i = 0; i < s.length(); ++i) {
        // Check if the current index matches the next space index
        if (spaceIndex < n && i == spaces[spaceIndex]) {
            result += ' '; // Add a space
            ++spaceIndex;  // Move to the next space index
        }
        result += s[i]; // Add the current character
    }

    return result;
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    int n;
    cout << "Enter the number of spaces: ";
    cin >> n;

    vector<int> spaces(n);
    cout << "Enter the indices for spaces: ";
    for (int i = 0; i < n; ++i) {
        cin >> spaces[i];
    }

    string result = addSpaces(s, spaces);
    cout << "Modified string: " << result << endl;

    return 0;
}
