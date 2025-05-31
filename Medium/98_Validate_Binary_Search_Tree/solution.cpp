#include <limits.h>
#include <queue>
#include <vector>
#include <climits>

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
    // this is wrong approach see video
    // https://youtu.be/s6ATEkipzow?si=nDjYmJpUhxNw7-Ce&t=140
    // bool isValidBST(TreeNode *root) {
    //     if (!root) {
    //         return true;
    //     }
    //     if (root->left) {
    //         if ((root->left)->val < root->val) {
    //             return true;
    //         }
    //         return false;
    //     }
    //     if (root->right) {
    //         if ((root->right)->val > root->val) {
    //             return true;
    //         }
    //         return false;
    //     }
    //     return isValidBST(root->left) && isValidBST(root->right);
    // }
    bool isValidBST(TreeNode *root) {
        long long maxRange = LLONG_MAX;
        long long minRange = LLONG_MIN;
        return dfs(root,maxRange,minRange);
    }

private:
    static bool dfs(const TreeNode *root, const long long maxRange, const long long minRange) {
        if (!root) {
            return true;
        }
        if (root->val>=maxRange || root->val<=minRange) {
            return false;
        }
        return dfs(root->left,root->val,minRange) && dfs(root->right,maxRange,root->val);
    }
};
