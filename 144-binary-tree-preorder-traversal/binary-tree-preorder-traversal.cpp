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
private:
    void func(TreeNode* node, vector<int>& ans){
        //if node is null then its the last node thus all the nodes of that subtree has been traversed thus return;
        if(node == NULL)
            return;
        
        //preorder stores node first thus add the node to the list
        ans.push_back(node->val);

        //traverse towards left to store the left nodes
        func(node->left, ans);

        //traverse towards right to store right nodes thus completing NLR
        func(node->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //stores answer list
        vector<int> ans;

        //temp node to keep root node safe
        TreeNode* node = root;

        //recursive function for preorder traversal
        func(node, ans);

        //return answer list
        return ans;
    }
};

// T.C : O(n), as all nodes will be traversedd at least once
//S.C : O(h), h->height of the tree, stack space required for recursion and O(n) for answer array.