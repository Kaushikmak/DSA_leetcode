#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(const int n) {
        vector<int> result;
        for (int i = 1; i <= 9; ++i) {
            dfs(i, n, result);
        }
        return result;
    }

private:
    void dfs(const int current, const int n, vector<int> &result) {
        if (current > n) return;
        result.push_back(current);
        for (int i = 0; i <= 9; ++i) {
            const int next = current * 10 + i;
            if (next > n) return;
            dfs(next, n, result);
        }
    }
};
