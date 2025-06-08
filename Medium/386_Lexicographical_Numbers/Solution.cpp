#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    struct comp {
        bool operator()(const int &num1, const int &num2) const {
            return to_string(num1) > to_string(num2);
        }
    };

    static vector<int> lexicalOrder(int n) {
        priority_queue<int, vector<int>, comp> minHeap;
        for (int i = 1; i <= n; ++i) {
            minHeap.push(i);
        }
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};
