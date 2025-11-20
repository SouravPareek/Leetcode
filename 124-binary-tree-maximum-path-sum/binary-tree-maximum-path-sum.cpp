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
    int findMaxPathSum(TreeNode* node, int& maxSum){
        //if node dont have a child then return 0
        if(!node)   
            return 0;
        
        //first move to the leftmost side of the parent and then start the calculation using recursion, but if the node is less than 0 than add 0 only else add it's value
        int lh = max(0, findMaxPathSum(node->left, maxSum));

        //after left child is traversed traverse to right child and similarly add the value
        int rh = max(0, findMaxPathSum(node->right, maxSum));

        //for each node add its inverted U shaped nodes to get the sum and keep track of maxSum
        maxSum = max(maxSum, node->val + lh + rh);

        //if a node isnt the root one then only either of the child's can be added so chosse the one with max value
        return node->val + max(lh, rh);
    }
public:
    int maxPathSum(TreeNode* root) {
        //maxSum  stores the maxPathSum found in functioning
        int maxSum = INT_MIN;

        //finds the maxPathSum and stores un maxSum
        findMaxPathSum(root, maxSum);

        return maxSum;
    }
};

//T.C : O(n), as all the nodes are traversedd once
//S.C : O(h), h->height of the tree, recursion stack will use space based on height only and it can be O(n) in worst case as in skewed tree