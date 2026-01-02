//optimal
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
    TreeNode* Helper(vector<int>& preorder, int bound, int& idx){
        //if all the elements are traversed or the element encountered is out of bound than return nullptr as it is not following the conditon of bst and might be parrt of another subtree
        if(idx == preorder.size() || preorder[idx] > bound)
            return nullptr;
        
        //create a new node having value of current index of preorder array
        TreeNode* node = new TreeNode(preorder[idx++]);
        
        //traverse left or right recursively to auto build tree
        node->left = Helper(preorder, node->val, idx);
        node->right = Helper(preorder, bound, idx);

        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return Helper(preorder, INT_MAX, idx);
    }
};

//T.C : O(N), due to visiting each node once in the preorder traversal.

//S.C : O(h), where h is the height of the tree due to recursion stack.