//lec code 
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
    TreeNode* Helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap){
        //if start indexes exceeds the end indexes then return NULL
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        
        //create a new Treenode with value at the current preStart
        TreeNode* root = new TreeNode(preorder[preStart]);

        //find the location of current root element in inorder traversal
        int inRoot = inMap[root->val];

        //calculate the number of elments left in left subtree
        int numsLeft = inRoot- inStart;

        //recursively build the left subtree
        root->left = Helper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        
        //recursively build the right subtree
        root->right = Helper(preorder, preStart + numsLeft +1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        //return the current root node
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //map to store indices of elements in the inorder traversal
        unordered_map<int, int> inMap;

        //map all the values of inorder traversal with position
        for(int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        //call the helper function to recursively build the tree
        return Helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    }
};

//T.C : O(n), Each node of the BT is visited once
//S.C : O(n), map stores all the n elements, additional auxillariy stack space O(h) is used, h->height of the tree