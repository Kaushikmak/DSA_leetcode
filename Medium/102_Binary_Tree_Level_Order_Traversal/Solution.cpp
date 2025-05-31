#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

using namespace std;

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        return bfs(root);
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
};
