
class Solution {
public:
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
};
