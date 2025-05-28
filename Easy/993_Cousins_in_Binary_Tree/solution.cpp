#include <queue>
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
    bool isCousins(TreeNode *root, int x, int y) {
        if (!root) return false;

        queue<pair<TreeNode *, TreeNode *> > q; // (node, parent)
        q.push({root, nullptr});

        while (!q.empty()) {
            int size = q.size();
            TreeNode *xParent = nullptr;
            TreeNode *yParent = nullptr;

            for (int i = 0; i < size; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) xParent = parent;
                if (node->val == y) yParent = parent;

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }

            if (xParent && yParent) {
                return xParent != yParent;
            } else if (xParent || yParent) {
                return false; // found only one at this level
            }
        }

        return false;
    }
};
