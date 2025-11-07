//iterative approach

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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // ans array to store the answer
        vector<int> ans;

        //stack to track the nodes already visited but didnt added to answer array
        stack<TreeNode*> st;

        //check if root node is null or not
        if(root == NULL)
            return ans;

        //dummy node for root node protection
        TreeNode* node = root;

        //push the root node to stack to start with
        st.push(node);

        //here we are pushing root node first then right and then left. that is opposite of postorder as using the starightforward approach would take more space and time so here we will reverse the answer array at last to get our answer
        while(!st.empty()){
            //use the node at top of the stack
            node = st.top();
            st.pop();

            //add value to ans array
            ans.push_back(node->val);

            //first push the nodes from left and then from right so that nodes on right remains above nodes on left so that nodes on left can be used further when its their turn
            if(node->left)
                st.push(node->left);
            
            if(node->right)
                st.push(node->right);
            
        }

        //reverse the answer array to get the required correct answer
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
