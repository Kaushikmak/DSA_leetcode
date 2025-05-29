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
        vector<int> result;
        vector<vector<int> > answer = levelOrdertraversal(root);
        const int size = answer.size();
        for (int i = 0; i < size; ++i) {
            result.push_back(answer[i][0]);
        }
        return result;
    }

private:
    static vector<vector<int> > levelOrdertraversal(TreeNode *root) {
        vector<vector<int> > result;
        if (root == nullptr) return result;
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty()) {
            vector<int> current;
            const int currentSize = q.size();

            for (int i = 0; i < currentSize; ++i) {
                const TreeNode *node = q.front();
                q.pop();
                current.push_back(node->val);
                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }
            }
            result.push_back(current);
        }
        return result;
    }
};
