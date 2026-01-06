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
    vector<int> inorder;
    int idx;

    //find the current inorder of the give tree
    void collect(TreeNode* node){
        if(node){
            collect(node->left);
            inorder.push_back(node->val);
            collect(node->right);
        }
    }

    //restore the tree by assigning sorted inorder values to nodes
    void restore(TreeNode* node){
        if(node){
            restore(node->left);
            node->val = inorder[idx++];
            restore(node->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        collect(root);

        //sort to get the required order of the nodes
        sort(inorder.begin(), inorder.end());

        restore(root);
    }
};

// T.C : O(nlogn), O(n) for collecting current inorder, O(n) fro restoring, O(nlogn) for sorting
// S.C : O(n), O(n) for storing inorder, O(n) stack space due to recursion
