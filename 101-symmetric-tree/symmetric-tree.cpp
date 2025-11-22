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
    bool check(TreeNode* p, TreeNode* q){
        //if either if the left and right side of tree are null then check if they are equal or not
        if(p == NULL || q == NULL)
            return (p == q);
        
        //compare value of the nodes, recurse tree for left nd right side trying to mirror in recursion
        return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};

//T.C : O(n), as each node in the tree is traversed once
//S.C : O(h), This is because the maximum depth of the recursion stack is equal to the height of the tree. In worst case (skewed tree) h = n and therefore T.C = O(n)