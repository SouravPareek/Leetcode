//optimal from solutions

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
        //ans stores the answer array to be returned
        vector<vector<int>> ans;

        //stores the nodes for level wise access
        queue<TreeNode*> q;

        //stores th enodes for each level and then pushes into the ans
        vector<int> level;

        //if root node is empty return empty vector of vector
        if(!root)
            return ans;
        
        //start by pushinh the root node to queue to start with
        q.push(root);
        //nullptr tells us about the end of the level as if nullptr is encountered then all the nodes of that level have been traversed now move to next level
        q.push(NULL);

        while(!q.empty()){
            //node initialize to first node of the tree or subtree to start with
            TreeNode* node = q.front();
            
            //if node is not null then push its value to the level array
            if(node)
                level.push_back(node->val);
            
            //now pop the value form front of the queue once it's traversed
            q.pop();

            //if node is null it means all the nodes of that level have been traversed , now push the level array to the answer and clear it to mive to the next level
            if(!node){
                ans.push_back(level);
                level.clear();

                //push null to the queue so that we can know the level is changed so it can be known that the new pushed nodes into the queue are of new level
                if(!q.empty())
                    q.push(NULL);
            }
            //if node is not null the push the childs of all the nodes from current level into the queue
            else{
                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};
