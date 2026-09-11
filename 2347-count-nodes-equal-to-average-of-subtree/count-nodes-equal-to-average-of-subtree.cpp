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
    int cnt = 0;
    pair<int, int> postorder(TreeNode* root){
        if(!root){
            return {0, 0};
        }

        pair<int, int> left = postorder(root->left);
        pair<int, int> right = postorder(root->right);

        int nodeSum = left.first + right.first + root->val;
        int nodeCnt = left.second + right.second + 1;

        if(root->val == (nodeSum/nodeCnt))
            cnt += 1;
        
        return {nodeSum, nodeCnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return cnt;
    }
};