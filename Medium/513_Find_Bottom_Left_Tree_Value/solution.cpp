#include <cstddef>
#include <limits.h>
#include <queue>
/**
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        vector<vector<int>> result = levelOrdertraversal(root);
        vector<int> lastRow = result.back();
        return lastRow.back();
    }

private:
    static vector<vector<int> > levelOrdertraversal(TreeNode *root) {
        vector<vector<int> > result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int levelsize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelsize; ++i) {
                const TreeNode *temp = q.front();
                q.pop();
                currentLevel.push_back(temp->val);
                // from right to left
                if (temp->right) {
                    q.push(temp->right);
                }
                if (temp->left) {
                    q.push(temp->left);
                }
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};

