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
    TreeNode* helper(vector<int>& arr, int st, int end){
        if(st == end)
            return nullptr;
        
        int mid = (st+end)/2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = helper(arr, st, mid);
        root->right = helper(arr, mid+1, end);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};