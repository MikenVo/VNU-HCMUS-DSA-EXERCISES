#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void backtrack(int index, string current_string, vector<string> &combo, const string &s) {
    if (current_string.size() == s.size()) { // If the current string == s, we add the string into the array
        combo.push_back(current_string); // Push back the strings that meet the requirements
        return;
    }

    char c = s[index]; // Take out one character
    if (isalpha(c)) { // Check if it is in the alphabet
        // The process keeps adding the characters until the string == s
        // Return back to the previous to try other combination
        
        // Example: a1
        // index = 0, current_string = "", combo = [], s = "a1"
        // c = a (true)

        // - index = 1, current_string = "a", combo = [], s = "a1"
        // - c = 1 (false)
        // - - index = 2, current_string = "a1", combo = ["a1"], s = "a1"

        // - index = 1, current_string = "A", combo = [], s = "a1"
        // - c = 1 (false)
        // - - index = 2, current_string = "A1", combo = ["a1", "A1"], s = "a1"
        backtrack(index + 1, current_string + (char)tolower(c), combo, s); // Add the lower character into the new string
        backtrack(index + 1, current_string + (char)toupper(c), combo, s); // Add the upper character into the new string
    }
    else {
        backtrack(index + 1, current_string + c, combo, s); // The character is not in the alphabet, add it into the new string
    }

    return;
}

vector<string> letterCasePermutation(string s) {
    vector<string> combo;
    backtrack(0, "", combo, s);
    return combo;
}

int main() {
    string s; cout << "Type a string: "; cin >> s;
    vector<string> combo = letterCasePermutation(s);

    cout << "[";
    for (int i = 0; i < combo.size(); i++) {
        if (i == combo.size() - 1) {
            cout << combo[i];
            break;
        } 
        cout << combo[i] << ", ";
    }
    cout << "]";

    return 0;
}

// Time complexity: O(N * 2^N) with k is the length of the string
// Space complexity: O(N * 2^N)

// Test cases
// Input: a1
// Output: ["a1", "A1"]

// Input: bc2
// Output: ["bc2","bC2","Bc2","BC2"]

// Input: akm321
// Output: ["akm321","akM321","aKm321","aKM321","Akm321","AkM321","AKm321","AKM321"]