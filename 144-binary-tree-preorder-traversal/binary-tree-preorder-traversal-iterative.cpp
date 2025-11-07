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
    vector<int> preorderTraversal(TreeNode* root) {
        //list to store preorder traversal
        vector<int> ans;

        //stack tracks the nodes to be traversed
        stack<TreeNode*> st;

        //if initial root node is null then no need to traverse
        if(root == NULL)
            return ans;

        //a dummy node of root node to use for traversal
        TreeNode* node = root;

        //initially push the root node to the stack as in preorder node comes firt then left and then right nodes
        st.push(node);

        //while loop ensures all the nodes have been traversed or not
        while(!st.empty()){
            
            //assign the node at top of stack to node to perform operations on that
            node = st.top();
            //pop that node as it's used
            st.pop();

            //first store the value of current node
            ans.push_back(node->val);

            //store right node before left as top of the stack will be left and when the operations on left node is completed then move back to the right nodes to traverse right half of the tree/sub-tree


            if(node->right != NULL)
                st.push(node->right);
            
            if(node->left != NULL)
                st.push(node->left);
        }

        return ans;
    }
};

//T.C. : O(n), as all the nodes of the tree needs to be traversed
//S.C. : O(n), as stack might need to store all the nodes at a time 
