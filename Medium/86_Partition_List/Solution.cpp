struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // assign pointers
        ListNode *leftPointer = head;
        ListNode *rightPointer = head;
        ListNode *iterator = head;
        while (iterator->next != nullptr) {
            iterator = iterator->next;
        }
        rightPointer = iterator;
        //
        while (leftPointer->next != rightPointer->next) {
            if (leftPointer->val > x) {

                leftPointer = leftPointer->next;
            }
            if (rightPointer->val<x) {

            }
        }
    }
};
