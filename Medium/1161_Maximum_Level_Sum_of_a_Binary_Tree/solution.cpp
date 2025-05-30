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
    int maxLevelSum(TreeNode *root) {
        vector<vector<int> > mat = bfs(root);
        vector<int> sumArray;
        const int matSize = mat.size();
        for (int i = 0; i < matSize; ++i) {
            sumArray.push_back(sum(mat[i]));
        }
        return 1 + indexOfMaximum(sumArray);
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
            const int levelSize = q.size();
            vector<int> current;
            for (int i = 0; i < levelSize; ++i) {
                const TreeNode *node = q.front();
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
        const int numsSize = nums.size();
        for (int i = 0; i < numsSize; ++i) {
            sum += nums[i];
        }
        return sum;
    }

    static int indexOfMaximum(const vector<int> &nums) {
        int max = INT_MIN;
        int index = -1;
        const int numSize = nums.size();
        for (int i = 0; i < numSize; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        return index;
    }
};
