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

// naive approach: inorder + any other traversal
// better approach: use any order traversal and special markers for null i.e. -1
// n nodes have 2n+1 nulls

class Solution {
public:
    vector<int> serialization(TreeNode *root) {
        vector<int> result;
        _preOrderSerialization(root, result);
        return result;
    }

    TreeNode *deserialization(vector<int> &serializedArray) {
        int index = 0;
        return _deserialization(serializedArray, index);
    }

private:
    static constexpr int EMPTY = INT_MIN;

    static void _preOrderSerialization(const TreeNode *root, vector<int> &nums) {
        if (root == nullptr) {
            nums.push_back(EMPTY);
            return;
        }
        nums.push_back(root->val);
        _preOrderSerialization(root->left, nums);
        _preOrderSerialization(root->right, nums);
    }

    static TreeNode *_deserialization(vector<int> &nums, int &index) {
        if (index == nums.size()) return nullptr;

        int val = nums[index++];
        if (val == EMPTY) return nullptr;

        auto *root = new TreeNode(val);
        root->left = _deserialization(nums, index);
        root->right = _deserialization(nums, index);
        return root;
    }
};
