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
private:
    bool valid(TreeNode* node, long maximum, long minimum){
        if(!node)
            return true;

        if(!(node->val < maximum && node->val > minimum)){
            return false;
        }
        return (valid(node->left, node->val, minimum) && valid(node->right, maximum, node->val));
    }
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MAX, LONG_MIN);
    }
};