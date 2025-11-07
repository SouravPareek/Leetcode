//recursive approach lec

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
    void recursiveInorder(TreeNode* node, vector<int>& ans){
        if(node == NULL)
            return;
        
        //left side traversal
        recursiveInorder(node->left, ans);

        //adding the data of node to list
        ans.push_back(node->val);
        
        //traversing towards right
        recursiveInorder(node->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        //new pointer to root node so that root node doesn't get manipulated during process 
        TreeNode* node = root;
        recursiveInorder(node, ans);

        return ans;
    }
};

//T.C : O(n), as all the nodes will be traversed at least once for inorder traversal
//S.C : O(h), h->height of the BT for recursion stack and O(n) for answerr array
