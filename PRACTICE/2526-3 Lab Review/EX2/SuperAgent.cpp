#include <iostream>
#include <cstring>
using namespace std;

void reverse(char seq[], char newseq[], int MAX) {
    for (int i = 0, j = MAX - 1; i <= MAX / 2, j >= 0; i++, j--) {
        newseq[i] = seq[j];
    }
}

int main() {
    // Flatten the 2D array
    // Reverse the sequence
    // Compare the reverse version and the original version
    // - If they are similar, print YES
    // - If they are not, print NO

    int MAX = 9;
    char* seq = new char[MAX + 1]();
    for (int i = 0; i < MAX; i++) {
        cin >> seq[i];
    }

    char* newseq = new char[MAX + 1]();
    reverse(seq, newseq, MAX);

    if (strcmp(newseq, seq) == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}

// Time complexity: O(1)
// Space complexity: O(1)

// Test cases
/* Input:
*  X.X
*  X.X
*  ...
*/
// OUTPUT: NO

/* INPUT:
*  X.X
*  ...
*  X.X
*/
// OUTPUT: YES

/* INPUT:
*  .X.
*  XXX
*  .X.
*/