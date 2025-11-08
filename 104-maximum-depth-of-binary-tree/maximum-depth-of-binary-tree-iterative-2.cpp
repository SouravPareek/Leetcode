//iterative sol (optimal)

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
    int maxDepth(TreeNode* root) {
        //if root is null then height of tree is 0
        if(!root)
            return 0;
        
        //depth tracks the height of the tree
        int depth = 0;

        //tracks the node of the tree and their traversal
        queue<TreeNode*> q;

        //initially push the root node in queue to start the traversal
        q.push(root);

        //null tacks the level of the tree
        q.push(NULL);

        while(!q.empty()){
            //use the node at front of the queue to move to the required level
            TreeNode* node = q.front();

            //pop the node , indicating that the node have been traversed
            q.pop();

            //if(node is null this implies the level has been changed and if q is empty that implies the traversal is complete and all nodes are visited)
            if(!node){
                depth += 1;
                
                //if node is null but queue isnt empty that means just change of level so push another null that helps future judgmnet of level change
                if(!q.empty())
                    q.push(NULL);
            }
            //if node is not null the push the left nd right vhildd to the queue
            else{
                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            } 
        }
        return depth;
    }
};

//T.C : O(n), as all the nodes are traversed.
//S.C : O(w), where w is the maximum width of the binary tree. In the worst case (complete binary tree), w can be n/2, so the space complexity can be considered O(n).
