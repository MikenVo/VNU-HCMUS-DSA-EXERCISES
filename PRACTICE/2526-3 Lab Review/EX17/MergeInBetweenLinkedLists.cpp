#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    ListNode *prior = list1;
    ListNode *post = list1;
    ListNode *del = nullptr;
    ListNode *post2 = list2;

    // Move the pointer to the a-th position
    for (int i = 0; i < a - 1; i++)
    {
        prior = prior->next;
    }

    // Move the pointer to the b-th position
    for (int i = 0; i < b + 1; i++)
    {
        post = post->next;
    }

    // Delete the elements between a and b
    del = prior->next;
    while (del != post)
    {
        ListNode *nextdel = del->next;
        delete del;
        del = nextdel;
    }

    // Link the second list into the first list
    prior->next = list2;

    while (post2->next != nullptr)
    {
        post2 = post2->next;
    }
    post2->next = post;

    return list1;
}

ListNode *CreateNode(int x)
{
    return new ListNode(x);
}

void AddTail(ListNode *&head, int x)
{
    ListNode *newNode = CreateNode(x);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    ListNode *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val;
        if (curr->next != nullptr)
            cout << " -> ";
        curr = curr->next;
    }
    cout << " -> nullptr" << endl;
}

void freeList(ListNode *head)
{
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int size1 = 6;
    int size2 = 3;
    int a = 3, b = 4;

    int *arr1 = new int[size1]{10, 1, 13, 6, 9, 5};
    int *arr2 = new int[size2]{1000001, 1000002, 1000003};

    ListNode *list1 = nullptr;
    ListNode *list2 = nullptr;

    for (int i = 0; i < size1; i++)
    {
        AddTail(list1, arr1[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        AddTail(list2, arr2[i]);
    }

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    ListNode *result = mergeInBetween(list1, a, b, list2);

    cout << "Result: ";
    printList(result);

    delete[] arr1;
    delete[] arr2;
    freeList(result);

    return 0;
}

// Time complexity: O(N + M)
// Space complexity: O(1) 