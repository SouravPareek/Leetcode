//optimal approach

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
    //recursive height function to calculate height of the tree
    int func(TreeNode* node, int& diameter){
        if(!node)
            return 0;
        
        //height of left part
        int lh = func(node->left, diameter);

        //height of right part
        int rh = func(node->right, diameter);

        //helps to store the max diamter found during the whole process
        diameter = max(diameter, lh+rh);

        //adds one to the height each time traversing back to the parent node for each child node
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        
        func(root, diameter);
        
        return diameter;
    }
};

//T.C :  O(N), In this approach, for each node, we calculate the height of its left and right subtrees by reursion, traversing each node only once which takes O(N) time.
//S.C :  O(H) The space complexity is determined by the maximum depth of the recursion stack, which corresponds to the height of the tree, H. Thus, the space complexity is O(H).