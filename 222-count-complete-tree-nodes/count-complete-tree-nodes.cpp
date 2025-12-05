//brute self
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
    void inorder(TreeNode* node, int& cnt){
        if(!node)
            return;
        
        cnt += 1;

        inorder(node->left, cnt);
        inorder(node->right, cnt);
    }
public:
    int countNodes(TreeNode* root) { 
        int cnt = 0;
        inorder(root, cnt);
        return cnt;
    }
};

//T.C: O(n), as each node is traversed once
//S.C : O(n), recursive stack space uses O(logn), in worst case like skewed tree it is O(n)