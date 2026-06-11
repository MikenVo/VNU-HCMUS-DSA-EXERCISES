#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s; cin >> s;
    stack<int> st;
    st.push(0);

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(0);
        }
        else {
            int current_score = st.top();
            st.pop();

            int parent_score = st.top() + std::max(2 * current_score, 1);
            st.pop();
            st.push(parent_score);
        }
    }
    
    cout << st.top() << endl;

    return 0;
}