//self dfs(recursion)

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
    //DFS helper: visit right child first to ensure rightmost node is captured first at each level
    void dfs(TreeNode* node, int level, vector<int>& ans){
        if(!node)
            return;
        
        //If we're visiting this level for the first time, the current node is the rightmost node at this level
        if(level == ans.size())
            ans.push_back(node->val);
        
        //First explore right subtree so rightmost nodes get precedence
        dfs(node->right, level+1, ans);
        dfs(node->left, level+1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        dfs(root, 0, ans);

        return ans;
    }
};

//T.C : O(n), We visit each node exactly once
//S.C : O(h), Recursion stack can go up to height h, in worst-case (skewed tree)->O(n)