//lec approach using dfs

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if root is NULL or root = p or root = q then return root as root will be LCA
        if(!root)
            return NULL;
        
        if(root == p || root == q)
            return root;
        
        //traverse towards left and right to find LCA
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        //if left is NULL then return right || //if right is NULL then return left
        if(!left || !right)
            return left ? left : right;
        //if both subtrees are not nullptr then thay have wanted pointers: one has p and anther has q, because we can get something differen than nullptr only if we find p,q or LCA, we find LCA in one of subtrees then we will have nullptr in the other one, because both p and q are available in that subtree where LCA is, so the another one is nullptr
        else
            return root;
    }
};

// T.C : O(n), as all nodes are traversed exatly once
//S.C : O(h), h->height of the subtree, that is recursion stack, in worst case h = n