#include <queue>
#include <string>
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
    // global var to keep track
    string result = "";

    string smallestFromLeaf(TreeNode *root) {
        dfs(root, "");
        return result;
    }

private:
    void dfs(const TreeNode *root, string curr) {
        if (!root) {
            return;
        }
        curr = static_cast<char>(root->val + 'a') + curr;
        if (!root->left && !root->right) {
            if (result.empty() || result > curr) {
                result = curr;
            }
            return;
        }
        dfs(root->left, curr);
        dfs(root->right, curr);
    }
};
