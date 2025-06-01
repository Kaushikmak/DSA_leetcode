#include <algorithm>
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
    // inorder is sorted
    // find inorder sort it and arrange nodes accordingly
    // think of optimized approach!!
    void recoverTree(TreeNode *root) {
        vector<int> inorderArray;
        inOrder(root, inorderArray);
        vector<int> sortedInorderArray = inorderArray;
        sort(sortedInorderArray.begin(), sortedInorderArray.end());
        vector<int> indexToBeChanged;
        for (int i = 0; i < inorderArray.size(); ++i) {
            if (sortedInorderArray[i] != inorderArray[i]) {
                indexToBeChanged.push_back(sortedInorderArray[i]);
            }
        }
        if (indexToBeChanged.size() == 2) {
            change(root, indexToBeChanged[0], indexToBeChanged[1]);
        }

    }

private:
    static void inOrder(const TreeNode *root, vector<int> &nums) {
        if (root) {
            inOrder(root->left, nums);
            nums.push_back(root->val);
            inOrder(root->right, nums);
        }
    }

    static void change(TreeNode *root,const int val1,const int val2) {
        if (root) {
            if (root->val == val1) {
                root->val = val2;
            } else if (root->val == val2) {
                root->val = val1;
            }

            change(root->left, val1, val2);
            change(root->right, val1, val2);
        }

    }

    static void swap(TreeNode *node1,TreeNode *node2) {
        const int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
};
