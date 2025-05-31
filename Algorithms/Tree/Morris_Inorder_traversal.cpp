#include <iostream>
#include <limits.h>
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


class MorrisInOrder {
public:
    // in order but iterative
    // we need stack, either use OS stack using recursion or use our own stack OR use morris traversal
    // https://www.youtube.com/watch?v=Wq3ibaP4dJY
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    vector<int> morrisOrder(TreeNode *root) {
        vector<int> result;
        TreeNode *current = root;
        while (current != nullptr) {
            if (current->left == nullptr) {
                // if no left then it is leftmost then print it
                result.push_back(current->val);
                current = current->right;
            } else {
                TreeNode *leftChild = current->left;
                while (leftChild->right != nullptr) {
                    leftChild = leftChild->right;
                }
                leftChild->right = current;
                TreeNode *temp = current;
                current = current->left;
                temp->left = nullptr;
            }
        }
        return result;
    }
};
