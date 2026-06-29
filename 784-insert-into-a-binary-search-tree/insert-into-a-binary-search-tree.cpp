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
 //self cleanest
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(!root)
            return newNode;

        TreeNode* node = root;

        while(true){
            if(val < node->val){
                if(node->left)
                    node = node->left;
                else{
                    node->left = newNode;
                    break;
                }
            }else{
                if(node->right)
                    node = node->right;
                else{
                    node->right = newNode;
                    break;
                }
            }
        }
        return root;
    }
};