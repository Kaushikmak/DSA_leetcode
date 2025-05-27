#include <limits.h>
#include <vector>


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

using namespace std;

// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder);
    }

private:
    TreeNode* build(vector<int> inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;

        int rootVal = postorder.back();
        postorder.pop_back();
        TreeNode* root = new TreeNode(rootVal);

        vector<vector<int>> splitted = split(inorder, rootVal);
        vector<int> leftInorder = splitted[0];
        vector<int> rightInorder = splitted[1];
        rightInorder.erase(rightInorder.begin());

        root->right = build(rightInorder, postorder);
        root->left = build(leftInorder, postorder);

        return root;
    }

    static vector<vector<int>> split(vector<int>& nums, const int target) {
        vector<int> array1;
        vector<int> array2;
        const int arraySize = nums.size();
        int i = 0;
        for (; i < arraySize; ++i) {
            if (nums[i] == target) {
                break;
            }
            array1.push_back(nums[i]);
        }
        for (; i < arraySize; ++i) {
            array2.push_back(nums[i]);
        }
        return {array1, array2};
    }
};

