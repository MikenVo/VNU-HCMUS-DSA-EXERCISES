#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Simple recursive approach to find GCD
    int getGCD(int a, int b) {
        // Base case: if remainder is 0, return the divisor
        if (b == 0) {
            return a;
        }
        // Recursive step
        return getGCD(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // If list is empty or has only one node, no pairs exist
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* curr = head;

        // Traverse the linked list until we reach the end
        while (curr != NULL && curr->next != NULL) {
            // 1. Calculate GCD of the current node and the next node
            int gcdVal = getGCD(curr->val, curr->next->val);

            // 2. Create a new node with the GCD value
            ListNode* gcdNode = new ListNode(gcdVal);

            // 3. Insert the new node between curr and curr->next
            gcdNode->next = curr->next;
            curr->next = gcdNode;

            // 4. Move forward by 2 steps to process the next original pair
            curr = gcdNode->next;
        }

        return head;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Solution sol;

    // Test Case 1: [10, 20, 30]
    ListNode* head1 = new ListNode(10);
    head1->next = new ListNode(20);
    head1->next->next = new ListNode(30);
    printf("Test Case 1:\nInput:  10 20 30\nOutput: ");
    printList(sol.insertGreatestCommonDivisors(head1));

    // Test Case 2: [7, 14, 21, 28]
    ListNode* head2 = new ListNode(7);
    head2->next = new ListNode(14);
    head2->next->next = new ListNode(21);
    head2->next->next->next = new ListNode(28);
    printf("\nTest Case 2:\nInput:  7 14 21 28\nOutput: ");
    printList(sol.insertGreatestCommonDivisors(head2));

    // Test Case 3: [17, 13] (Số nguyên tố)
    ListNode* head3 = new ListNode(17);
    head3->next = new ListNode(13);
    printf("\nTest Case 3:\nInput:  17 13\nOutput: ");
    printList(sol.insertGreatestCommonDivisors(head3));

    return 0;
}

// Time complexity: O(N)
// Space complexity: O(1)