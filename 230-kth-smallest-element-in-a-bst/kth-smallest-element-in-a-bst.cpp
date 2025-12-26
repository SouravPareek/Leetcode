//self optimal
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
    void inorder(TreeNode* root, int& k, int& ans){
		if(root){
			inorder(root->left, k, ans);
			//if k is 0 then we have reached kth smallest elment thus it is ans and return
            if(--k == 0){
				ans = root->val;
				return;
			}
			
			inorder(root->right, k, ans);
		}
	}
public:
    int kthSmallest(TreeNode* root, int k){
		//ans stores the kth snallest element
        int ans = -1;
        //inorder traverfsal of a BST always gives sorted order
		inorder(root, k, ans);
		return ans;
	}
};