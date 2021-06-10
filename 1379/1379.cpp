/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        std::vector<int> targetPath;

        bool isFound = findNode(original, target, targetPath);
        if (isFound) {
            TreeNode* clonedTarget = cloned;
            for (int i = targetPath.size() - 1; i >= 0; i--) {
                if (targetPath[i] == 0) {
                    clonedTarget = clonedTarget->left;
                } else {
                    clonedTarget = clonedTarget->right;
                }
                
            }
            
            return clonedTarget;
        }
        
        return nullptr;
    }

    bool findNode(TreeNode* root, TreeNode* target, std::vector<int>& path) {
        if (root == nullptr) {
            return false;
        }

        if (root == target) {
            return true;
        }

        if (findNode(root->left, target, path)) {
            path.push_back(0);
            return true;
        } else if (findNode(root->right, target, path)) {
            path.push_back(1);
            return true;
        } else {
            return false;
        }
    }
};
