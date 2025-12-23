//self code
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //create a new node pointing to null as we will be be inserting new node at leaf position
        TreeNode* newNode = new TreeNode(val);

        if(!root)
            return newNode;
        
        //create a pointer to root node for traversing as we need to return root as it is so do not use root insetead create a seperate pointer
        TreeNode* cur = root;
        while(cur){
            //if value of node to be inserted is greater than value of current node move to right subtree
            if(val > cur->val){
                //if right child is null than we have reached our target position, so insert node at right
                if(cur->right == nullptr){
                    cur->right = newNode;
                    break;
                }
                cur = cur->right;
            }
            //if value of node to be inserted is lesser than value of current node move to left subtree
            else{
                //if lefft child is null than we have reached our target position, so insert node at left
                if(cur->left == nullptr){
                    cur->left = newNode;
                    break;
                }
                cur = cur->left;
            }
        }
        return root;
    }
};

// T.C : O(H), where H = log2(n), but in worst case it can be O(N) due to skewed tree
//S.C : O(1), no extra space used