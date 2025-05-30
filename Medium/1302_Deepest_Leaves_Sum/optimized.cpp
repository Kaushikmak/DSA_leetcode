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
        return bfs(root);
    }

private:
    static int bfs(TreeNode *root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            const int levelsize = static_cast<int>(q.size());
            sum = 0;

            for (int i = 0; i < levelsize; ++i) {
                const TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return sum;
    }
};
