//self brute
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
private:
    bool getPath(TreeNode* root, vector<int>& path, TreeNode* x){
        if(!root)
            return false;
        
        path.push_back(root->val);

        if(root->val == x->val)
            return true;
        
        if(getPath(root->left, path, x) || getPath(root->right, path, x))
            return true;
        
        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> path1, path2;

        if(!getPath(root, path1, p) || !getPath(root, path2, q))
            return nullptr;
        
        int i = 0;
        while(i < path1.size() && i < path2.size() && path1[i] == path2[i])
            i++;
        
        return new TreeNode(path1[i-1]);
    }
};
