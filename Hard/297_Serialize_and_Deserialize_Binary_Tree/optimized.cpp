#include <sstream>
#include <string>

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

class Codec {
public:
    string serialize(TreeNode *root) {
        string result;
        _preOrderSerialization(root, result);
        return result;
    }

    TreeNode *deserialize(string data) {
        istringstream ss(data);
        return _deserialization(ss);
    }

private:
    static constexpr auto EMPTY = "@";

    void _preOrderSerialization(const TreeNode *root, string &result) {
        if (root == nullptr) {
            result += string(EMPTY) + ",";
            return;
        }
        result += to_string(root->val) + ",";
        _preOrderSerialization(root->left, result);
        _preOrderSerialization(root->right, result);
    }

    TreeNode *_deserialization(istringstream &ss) {
        string token;
        getline(ss, token, ',');

        if (token == EMPTY) return nullptr;

        auto *node = new TreeNode(stoi(token));
        node->left = _deserialization(ss);
        node->right = _deserialization(ss);
        return node;
    }
};
