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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* maximumBinaryTree = new TreeNode();

        constructMaximumBinaryTree(maximumBinaryTree, nums);

        return maximumBinaryTree;
    }

    void constructMaximumBinaryTree(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }

        auto maxPos = max_element(nums.begin(), nums.end());
        root->val = *maxPos;
        vector<int> leftSubNums(nums.begin(), maxPos);
        vector<int> rightSubNums(maxPos + 1, nums.end());

        if (leftSubNums.size() > 0) {
            TreeNode* left = new TreeNode();
            root->left = left;
            constructMaximumBinaryTree(left, leftSubNums);
        }

        if (rightSubNums.size() > 0) {
            TreeNode* right = new TreeNode();
            root->right = right;
            constructMaximumBinaryTree(right, rightSubNums);
        }
    }
};
