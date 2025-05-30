#include <climits>
#include <queue>
#include <stdint.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        const vector<vector<int> > mat = bfs(root);
        const int matRows = mat.size();
        vector<int> finalArray = mat[matRows - 1];
        return sum(finalArray);
    }

private:
    static vector<vector<int> > bfs(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            const int levelsize = q.size();
            vector<int> current;
            for (int i = 0; i < levelsize; ++i) {
                TreeNode *node = q.front();
                q.pop();
                current.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(current);
        }
        return result;
    }

    static int sum(const vector<int> &nums) {
        int sum = 0;
        const int sizeNums = nums.size();
        for (int i = 0; i < sizeNums; ++i) {
            sum += nums[i];
        }
        return sum;
    }
};
