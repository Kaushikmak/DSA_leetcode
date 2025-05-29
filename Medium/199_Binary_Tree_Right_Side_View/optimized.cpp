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
    vector<int> rightSideView(TreeNode *root) {
        return levelOrdertraversal(root);
    }

private:
    static vector<int> levelOrdertraversal(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) return result;
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty()) {

            const int currentSize = q.size();

            for (int i = 0; i < currentSize; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (i==0) {
                    result.push_back(node->val);
                }
                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }
            }

        }
        return result;
    }
};
