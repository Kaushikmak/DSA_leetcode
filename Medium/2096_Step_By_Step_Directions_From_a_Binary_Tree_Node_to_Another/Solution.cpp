#include <queue>
#include <vector>
#include <string>

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
    string getDirections(TreeNode *root, int startValue, int destValue) {
        string pathToStart, pathToDest;

        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);

        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }

        string up(pathToStart.size() - i, 'U');
        string down = pathToDest.substr(i);

        return up + down;
    }

private:
    bool findPath(TreeNode *root, int value, string &path) {
        if (!root) return false;
        if (root->val == value) return true;

        path.push_back('L');
        if (findPath(root->left, value, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, value, path)) return true;
        path.pop_back();

        return false;
    }
};
