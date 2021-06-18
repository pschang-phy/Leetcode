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
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        bstToGst(root, 0);
        return root;
    }

    TreeNode* bstToGst(TreeNode* root, int offset) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* gst = bstToGst(root->right, offset);
        if (gst != nullptr) {
            root->val += gst->val;
        } else {
            root->val += offset;
        }

        gst = bstToGst(root->left, root->val);
        if (gst == nullptr) {
            return root;
        } else {
            return gst;
        }
    }
};
