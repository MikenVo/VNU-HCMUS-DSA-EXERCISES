// Read README.md in https://github.com/MikenVo/VNU-HCMUS-DSA-EXERCISES/tree/main/PRACTICE/2526-2%20Stack%20Queue/Queue to know the problem

#include <iostream>
#include <algorithm>
using namespace std;

// We need to sort the array in an ascending order.
// Take a variable i as a marker. We will calculate the total of elements prior to the marker.
// If the total is less than or equal to the "marker" element, we count as one satisfied customer.
// Else skip.

int main() {
	// Variable Initialization
	int num; cin >> num;
	int* arr = new int[num]();
	int mark = 0 /* Hold the index number of the checked element */, result = 0 /* Hold the number of satisfied people */, total = 0 /* Hold the total of the elements before
	the "marked" element */;

	// Input
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	// Sort the array
	sort(arr, arr + num);

	// Iterate through the array
	for (int i = 0; i < num; i++) {
		// Check if the "marked" element is not at the first position of the array
		if (mark != 0) {
			// Calculate the total of the elements before the "marked" element
			// E.g. 1 5 4 2 3 -> 1 2 3 4 5 (Sorted!)
			// 
			//      mark = 0 -> The marked element is 1
			//      1 is at the first position of the array. Therefore, move to the next element and increase result because the first person is always be satisfied
			//
			//      mark = 1 -> The marked element is 2
			//      2 is at the second position of the array. Therefore, calculate total = 1. Compare total < 2. Therefore, increase result and mark.
			//      
			//      ...
			// 
			//		If the marked element is "disappointed", we skip the element
			//
			//      The result is 3 (There are three people satisfied)
			if (total <= arr[mark]) {
				total += arr[mark];
				result++;
				mark++;
			}
			else {
				mark++;
			}
		}
		else {
			total += arr[mark];
			// If no, increase mark (move to the next element)
			mark++;
			// The first person in the queue is always be satisfied
			result++;
		}
	}

	cout << result << endl;

	return 0;
}