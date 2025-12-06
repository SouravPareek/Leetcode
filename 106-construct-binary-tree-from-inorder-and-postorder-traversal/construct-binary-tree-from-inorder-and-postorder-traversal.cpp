// self using in + pre
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
    TreeNode* Helper(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap){
        //if start indexes exceeds the end indexes then return NULL
        if(postStart > postEnd || inStart > inEnd)
            return NULL;
        
        //create a new Treenode with value at the current postStart
        TreeNode* root = new TreeNode(postorder[postEnd]);

        //find the location of current root element in postorder traversal
        int inRoot = inMap[root->val];

        //calculate the number of elments left in left subtree
        int numsLeft = inRoot- inStart;

        //recursively build the left subtree
        root->left = Helper(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, inMap);
        
        //recursively build the right subtree
        root->right = Helper(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);

        //return the current root node
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //map to store indices of elements in the inorder traversal
        unordered_map<int, int> inMap;

        //map all the values of inorder traversal with position
        for(int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        //call the helper function to recursively build the tree
        return Helper(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    }
};

//T.C : O(n), Each node of the BT is visited once
//S.C : O(n), map stores all the n elements, additional auxillariy stack space O(h) is used, h->height of the tree