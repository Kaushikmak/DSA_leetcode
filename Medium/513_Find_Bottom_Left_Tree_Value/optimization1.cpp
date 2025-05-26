class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        int bottomLeft = root->val;
        while (!q.empty()) {
            const int levelsize = q.size();
            bottomLeft = q.front()->val;
            for (int i = 0; i < levelsize; ++i) {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }

            }
        }
        return bottomLeft;
    }
};