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
        string binary;
        int res = 0;
        while (temp!=nullptr) {
            binary.push_back(temp->val+'0');
            temp = temp->next;
        }
        for (const char bits: binary) {
            res = (res<<1) | (bits-'0');
        }
        return res;

    }
};
