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
    void func(TreeNode* node, string path, vector<string>& ans){
        //if node is null that means all the nodes of that side of the subtree has been traversed and thus the path has ended
        if(!node)
            return;
        
        //add the current node value to the path
        path += to_string(node->val);

        //if a node doesnt have both left and right child then the path to reach that node fromroot is over and thus add it into the answer vector
        if((node->left == NULL) && (node->right == NULL)){
            ans.push_back(path);
            return;
        }

        path += "->";
        //recurse towards both left and right half to traverse all the nodes
        func(node->left, path, ans);
        func(node->right, path, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        //ans stores the output to be returned
        vector<string> ans;
        //path string is used to track all the paths during recursion
        string path = "";

        if(!root)
            return ans;
        
        func(root, path, ans);
        return  ans;
    }
};

//T.C : O(n), as each node is traversed exactly once
//S.C : O(h), where h->height of the tree as stack space used is equal to height of the tree, in case of skewed tree it can go upto O(n) as h = n