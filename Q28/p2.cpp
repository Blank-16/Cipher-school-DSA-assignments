#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

void printList(ListNode *node) {
    while (node) {
        cout << node->val;
        if (node->next)
            cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

void freeList(ListNode *head) {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    cout << "Original list: ";
    printList(head);
    Solution sol;
    ListNode *mid = sol.middleNode(head);
    cout << "Middle node value: " << mid->val << endl;
    cout << "List from middle node: ";
    printList(mid);
    freeList(head);
    return 0;
}
