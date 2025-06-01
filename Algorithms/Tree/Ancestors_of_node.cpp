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

// Recursive function to find ancestors of a target node
bool findAncestors(TreeNode* root, int target, vector<int>& ancestors) {
    // Base case 1: If the current node is null, return false
    if (root == nullptr)
        return false;

    // Base case 2: If the current node's value matches the target, return true
    if (root->val == target)
        return true;

    // Recursively search for the target in the left or right subtree
    bool foundInLeftSubtree = findAncestors(root->left, target, ancestors);
    bool foundInRightSubtree = findAncestors(root->right, target, ancestors);

    // If the target is found in either subtree, current node is an ancestor
    if (foundInLeftSubtree || foundInRightSubtree) {
        ancestors.push_back(root->val);  // Add current node to the list of ancestors
        return true;
    }

    // If target not found in either subtree, return false
    return false;
}
