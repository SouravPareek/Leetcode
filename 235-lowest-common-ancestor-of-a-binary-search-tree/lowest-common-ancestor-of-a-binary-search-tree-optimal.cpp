//self optimal
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
    //using recursion on LCA funtion to get the required answer
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        
        //if value of current node is lesser than both p and q's values than it implies LCA exist on left subtree, thus move to left
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        //if value of current node is greater than both p and q's values than it implies LCA exist on right subtree, thus move to right
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        
        ////if value of current node is neither greater than both p and q's or lesser than both p and q's values than it implies current node is LCA as after it both the nodes exist in seperate subtrees therfore current node is the LCA, thus return current node
        return root;
    }
};

//T.C: O(h), h->height of the tree, in case of skewed tree it can gonup to O(n)
//S.C: O(h), bcoz of the recursive stack space used, it can also go up to O(n) for skewed tree
