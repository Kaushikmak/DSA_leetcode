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
    int longestZigZag(TreeNode *root) {
        // Initialize the result
        int maxLength = 0;
        // Start recursive traversal to find the longest zigzag path
        goDown(root, true, 0, maxLength); // Start from the root with left direction

        return maxLength;
    }

private:
    // Recursive function to traverse and find zigzag path lengths
    void goDown(TreeNode *node, bool left, int length, int &maxLength) {
        // Base case: if node is null, return
        if (!node) return;

        // Update the maximum length found
        maxLength = max(maxLength, length);

        // Recursive calls to left and right children based on zigzag direction
        if (left) {
            // If coming from left, go right
            goDown(node->right, false, length + 1, maxLength);
            // If coming from left and no right child, go left
            goDown(node->left, true, 1, maxLength);
        } else {
            // If coming from right, go left
            goDown(node->left, true, length + 1, maxLength);
            // If coming from right and no left child, go right
            goDown(node->right, false, 1, maxLength);
        }
    }
};
