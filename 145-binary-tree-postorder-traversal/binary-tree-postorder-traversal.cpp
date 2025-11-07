//recursive approach

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
    void func(TreeNode* node, vector<int>& ans){
        //if node is null then we have reached one end of the parent node
        if(node == NULL)
            return;
        //move towards left side of the tree to print left side first
        func(node->left, ans);

        //traverse towards right to traverse towards right
        func(node->right, ans);

        //add the data to answer array
        ans.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //array to store answer
        vector<int> ans;

        //dummy node to keep root node safe of any errors or manipulation
        TreeNode* node = root;

        //recursive postorder function
        func(root, ans);

        return ans;
    }
};

//T.C : O(n), as traversing through all the nodes at least once
//S.C : O(n), The recursive stack space will be equal to the height of the tree, which can be O(N) in worst case (in case of skewed tree). also the answer array takes O(n) to store answer