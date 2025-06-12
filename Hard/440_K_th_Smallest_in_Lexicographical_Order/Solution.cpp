#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    struct comp {
        bool operator()(const int &a, const int &b) const {
            const string &sa = to_string(a);
            const string &sb = to_string(b);
            return sa < sb;
        }
    };

    int findKthNumber(int n, int k) {
        priority_queue<int, vector<int>, comp> heap;
        for (int i = 1; i <= n; ++i) {
            heap.push(i);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        return heap.top();
    }
};
