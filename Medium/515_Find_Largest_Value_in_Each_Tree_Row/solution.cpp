#include <climits>
#include <inttypes.h>
#include <queue>
#include <vector>
struct TreeNode;
/**
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
    static vector<int> largestValues(TreeNode *root) {
        const vector<vector<int> > allLevels = levelOrdertraversal(root);
        const int size = allLevels.size();
        vector<int> result;
        for (int i = 0; i < size; ++i) {
            result.push_back(findMax(allLevels[i]));
        }
        return result;
    }

private:
    static vector<vector<int> > levelOrdertraversal(TreeNode *root) {
        vector<vector<int> > result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int levelsize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelsize; ++i) {
                const TreeNode *temp = q.front();
                q.pop();
                currentLevel.push_back(temp->val);
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            result.push_back(currentLevel);
        }
        return result;
    }

    static int findMax(const vector<int> &nums) {
        int max = INT_MIN;
        const int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max;
    }
};
