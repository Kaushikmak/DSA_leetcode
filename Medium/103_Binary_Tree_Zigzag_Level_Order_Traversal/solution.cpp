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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        return dfs(root);
    }

private:
    static vector<vector<int> > dfs(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool flip = true;
        while (!q.empty()) {
            const int levelSize = static_cast<int>(q.size());
            vector<int> currentLevel(levelSize);
            for (int i = 0; i < levelSize; ++i) {
                const TreeNode *node = q.front();
                q.pop();
                const int index = flip ? i : (levelSize - 1 - i);
                currentLevel[index] = node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(currentLevel);
            flip = !flip;
        }
        return result;
    }
};
