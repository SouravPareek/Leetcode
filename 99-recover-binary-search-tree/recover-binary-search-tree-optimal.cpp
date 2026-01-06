//optimal approach
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
    TreeNode *first, *prev, *middle, *last;

    //find the current inorder of the give tree
    void Inorder(TreeNode* node){
        if(node){
            Inorder(node->left);
            
            //if prev node is not null, that means we are not at first node and than checkif prev node's value is greater than current node's val or not, if yes than it can be the swapped node and similarly check for each node and based on that find the nodes that are swapped
            if(prev && prev->val > node->val){
                if(!first){
                    first = prev;
                    middle = node;
                }else{
                    last = node;
                }
            }
            prev = node;

            Inorder(node->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        //initialize first, last, middle, prev pointer to null
        first = last = middle = prev = nullptr;

        //call the inorder
        Inorder(root);

        //check the nodes and swap the values
        if(first && last){
            swap(first->val, last->val);
        }else if(first && middle){
            swap(first->val, middle->val);
        }
    }
};
