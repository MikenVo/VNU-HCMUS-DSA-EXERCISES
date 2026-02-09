#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char* str = new char[1000001]; // Character array for input
	int* stack = new int[1000001](); // Character array to store the index number of each character. I take advantage of '\0'

	int top = 0, attempt = 0;
	int length = 0, substring = 1;
	int n;

	cin.getline(str, 1000001);
	n = strlen(str);
	stack[top] = -1;

	for (int i = 0; i < n; i++) {
		if (str[i] == '(') {
			stack[++top] = i;
		}
		else {
			top--;

			if (top < 0) {
				top = 0;
				stack[top] = i;
			}
			else {
				attempt = i - stack[top];
				if (attempt > length) {
					length = attempt;
					substring = 1;
				}
				else if (attempt == length && length > 0) {
					substring++;
				}
			}
		}
	}

	cout << length << " " << substring << endl;

	delete[] str;
	delete[] stack;
	return 0;
}