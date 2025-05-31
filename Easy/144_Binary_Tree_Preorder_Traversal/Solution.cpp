#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        helper(root,result);
        return result;

    }
private:
    void helper(TreeNode *root, std::vector<int> &nums){
        if(root){
            nums.push_back(root->val);
            helper(root->left,nums);
            helper(root->right,nums);
        }
    }
};
