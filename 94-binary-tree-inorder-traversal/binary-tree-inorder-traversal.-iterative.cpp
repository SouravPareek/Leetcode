 //iterative approach lec

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        //stack stores past nodes for future accessing
        stack<TreeNode*> st;

        TreeNode* node = root;

        while(true){
            //check if at leaf node or not, if not then push onto stack and move left
            if(node != NULL){
                st.push(node);
                node = node->left;
            }else{
                //if stack is empty , it implies all the nodes have been traversed thus end the while loop
                if(st.empty())
                    break;
                
                //if any node remains after traversing below it then move back to the parent node and traverse towards right
                node = st.top();
                st.pop();
                    
                ans.push_back(node->val);

                //traversing to right half og each subtree
                node = node->right;
            }
        }
        return ans;
    }
};

//T.C : O(n), as all nodes are traversed at least once
//S.C : O(h), h is height of the tree as stack will store at most h elements at any moment coz on traversing an element it will pop it out and then only mov to other half of the tree
