//lec

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //queue to track the nodes levelwise by using the fifo functionality
        queue<TreeNode*> q;
        
        //stores the ans
        vector<vector<int>> ans;

        //if the root is null then ans is empty array
        if(root == NULL)
            return ans;
        
        //start by pushing the root node to the quesue to start with
        q.push(root);
        
        //if queue is empty that means all the nodes have been traversed
        while(!q.empty()){
            //size of queue tells the no of elments to be added to answer in next level
            int size = q.size();

            //level array to store nodes of current aray
            vector<int> level;

            //for helps to store all the nodes of the same level in the answer with the help of size reference
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
                
            }
            ans.push_back(level);
        }
        return ans;
    }
};

//T.C : O(n), as all the nodes are traversed at least once
//S.C : O(n), as answer needs to store all the element of the tree, and in worst case queue also hold n/2 elements.
