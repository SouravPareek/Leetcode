//self code
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
    TreeNode* searchBST(TreeNode* root, int val) {
        //traverse the tree until we found the required node or we reach the end
        while(root && root->val != val){
            //move to left or right depending upon comparisons
            root = (root->val > val) ? root->left : root->right;
        }
        return root;
    }
};

//T.C : O(log2(N)), in bst search space is halved in each step, but in worst case (skewed tree) it can go up to O(N)
//S.C : O(1), no extra space used