#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

using namespace std;

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        return reverse(bfs(root));
    }

private:
    static vector<vector<int> > bfs(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            const int levelSize = q.size();
            vector<int> current;
            for (int i = 0; i < levelSize; ++i) {
                const TreeNode *node = q.front();
                q.pop();
                current.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(current);
        }
        return result;
    }

    static vector<vector<int> > reverse(vector<vector<int> > nums) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left < right) {
            _swap(nums[left], nums[right]);
            left++;
            right--;
        }
        return nums;
    }

    static void _swap(vector<int> &nums1, vector<int> &nums2) {
        const vector<int> temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }
};
