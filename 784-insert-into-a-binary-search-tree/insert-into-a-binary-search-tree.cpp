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
 //self
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(!root)
            return newNode;

        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while(node){
            prev = node;
            if(node->val > val){
                node = node->left;
            }else{
                node = node->right;
            }
        }
        if(prev){
            if(val > prev->val)
                prev->right = newNode;
            else
                prev->left = newNode;
        }
        
        return root;

    }
};