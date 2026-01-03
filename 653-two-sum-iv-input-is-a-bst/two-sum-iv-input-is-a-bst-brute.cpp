//self brute
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
	void helper(TreeNode* root, vector<int>& inorder){
		if(root){
			helper(root->left, inorder);
			inorder.push_back(root->val);
			helper(root->right, inorder);
		}
	}
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;

		helper(root, inorder);

		for(int i = 0; i < inorder.size()-1; i++){
			for(int j = i+1; j < inorder.size(); j++){
				if(inorder[i] + inorder[j] == k)
					return true;
			}
		}
		return false;
    }
};
