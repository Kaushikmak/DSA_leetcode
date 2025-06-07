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
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Get max sum from left and right subtrees
        // Use max(0, ...) to ignore negative paths
        int leftMax = max(0, maxPathSumHelper(node->left, maxSum));
        int rightMax = max(0, maxPathSumHelper(node->right, maxSum));

        // Current path sum including this node as the "peak"
        int currentPathSum = node->val + leftMax + rightMax;

        // Update global maximum
        maxSum = max(maxSum, currentPathSum);

        // Return the maximum path sum that can be extended upward
        // (either through left or right subtree, plus current node)
        return node->val + max(leftMax, rightMax);
    }
};
