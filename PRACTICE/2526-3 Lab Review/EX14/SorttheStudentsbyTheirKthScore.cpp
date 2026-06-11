#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem:
// 

vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    int n = score.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (score[j][k] < score[j + 1][k]) {
                swap(score[j], score[j + 1]);
            }
        }
    }

    return score;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> score(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> score[i][j];
        }
    }

    cout << "----------------" << endl;

    vector<vector<int>> result = sortTheStudents(score, 2);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}