#include <string>

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

using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode *head) {
        ListNode *temp = head;
        int res = 0;
        while (temp!=nullptr) {
            res = (res<<1) | temp->val;
            temp = temp->next;
        }

        return res;

    }
};
