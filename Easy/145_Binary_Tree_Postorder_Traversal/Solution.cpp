#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

private:
    void helper(TreeNode *root, vector<int> &nums) {
        if (root) {
            helper(root->left, nums);
            helper(root->right, nums);
            nums.push_back(root->val);
        }
    }
};
