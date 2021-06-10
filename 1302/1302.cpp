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
    int deepestLeavesSum(TreeNode* root) {
        setNodeDepth(root, 1);

        int sum = 0;
        for (auto node : m_NodeDepth.back()) {
            sum += node->val;
        }

        return sum;
    }
    
    void setNodeDepth(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }

        if (m_NodeDepth.size() < depth) {
            m_NodeDepth.push_back(std::vector<TreeNode*>(1, root));
        } else {
            m_NodeDepth[depth - 1].push_back(root);
        }

        if (root->left != nullptr) {
            setNodeDepth(root->left, depth + 1);
        }

        if (root->right != nullptr) {
            setNodeDepth(root->right, depth + 1);
        }
    }
    
private:
    std::vector<std::vector<TreeNode*>> m_NodeDepth;
};
