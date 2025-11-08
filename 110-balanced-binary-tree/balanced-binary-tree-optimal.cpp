//optimal

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
        
        //lh gets the left height
        int lh = height(node->left);

        if(lh == -1)
            return -1;

        //rh gets the right height
        int rh = height(node->right);

        if(rh == -1)
            return -1;
        
        //after each step of recusion height difference is checked , if difference > 1 then it's not a balanced BT thus returns -1;
        if(abs(lh-rh) > 1)
            return -1;

        return 1 + max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        //if height returned is -1 that means it's an unbalanced binary tree thus it returns false , else returns true
        return height(root) != -1;
    }
};

//T.C : O(n), at each step in worst case calculating height can take upto O(n).
//S.C : O(n), coz of the recursive stack space.
