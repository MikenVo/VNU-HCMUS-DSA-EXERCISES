#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char* str = new char[1000001];
	char* stack = new char[1000000]();
	int base = 0, attempt = 0;
	int length = 0, substring = 1;
	bool start = false;

	cin.getline(str, 1000001);
	stack[0] = '1';


	for (int i = 0; i < strlen(str); i++) {
		if (str[])
	}

	cout << length << " " << substring << endl;

	delete[] str;
	delete[] stack;
	return 0;
}