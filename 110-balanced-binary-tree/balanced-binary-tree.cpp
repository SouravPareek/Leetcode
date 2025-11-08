//brute

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
    //measures the height of tree using recursion
    int height(TreeNode* node){
        if(!node)
            return 0;
        
        //recurses throughout the tree both left and right sidde of each node
        return 1 + max(height(node->left), height(node->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        //lh gets the left height
        int lh = height(root->left);

        //rh gets the right height
        int rh = height(root->right);
        
        //after each step of recusion height difference is checkedd , if difference > 1 then it's not a balanced BT thus returns false;
        if(abs(lh-rh) > 1)
            return false;

        //recurses throughout the tree
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

//T.C : O(n^2), as traversing to each node in worst case takes O(n) and at each step in worst case calculating height can take upto O(n) which combines to O(n^2)
//S.C : O(n), coz of the recursive stack space used