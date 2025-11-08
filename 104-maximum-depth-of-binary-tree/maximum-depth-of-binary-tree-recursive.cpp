//recursive approach

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
    //recusrion is done in a way such that first it start from root node and then it move till leaf nodes once null is encountered then it starts moving up again counting left side andd right side for each sub tree
    int maxDepth(TreeNode* root) {
        //if root is null thus height is 0 as no node exist
        if(!root)
            return 0;
        
        // recurse towards left to get the max height left subtree
        int lh = maxDepth(root->left);

        // recurse towards right to get the max height right subtree
        int rh = maxDepth(root->right);

        //ones both the sides are traversed add 1 to depth and then move to next level
        return 1 + max(lh, rh);
    }
};

//T.C : O(n), this solution visits each node once thus time complexity beign O(n)
//S.C : O(h), it uses O(h) space due to the recursive function calls on the stack, where h is the height of the tree.
