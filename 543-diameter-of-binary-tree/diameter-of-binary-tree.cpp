//brute approach

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
    //recursive height function to calculate height of the tree
    int height(TreeNode* node){
        if(!node)
            return 0;
        
        return 1 + max(height(node->left), height(node->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        //height of left part
        int lh = height(root->left);

        //height of right part
        int rh = height(root->right);

        //left side diametr
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);

        return max(max(ld, rd), lh+rh);
    }
};

//T.C :  O(N^2), In this approach, for each node, we calculate the height of its left and right subtrees, which takes O(N) time. Since this calculation is done for each of the N nodes in the tree, the total time complexity is O(N * N) = O(N2)
//S.C :  O(H) The space complexity is determined by the maximum depth of the recursion stack, which corresponds to the height of the tree, H. Thus, the space complexity is O(H).