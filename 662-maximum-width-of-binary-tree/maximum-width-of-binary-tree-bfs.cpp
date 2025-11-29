//lec approach bfs

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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxWidth = 0;

        if(!root)
            return maxWidth;
        
        //queue, pair is used to store node along with its position in current level
        queue<pair<TreeNode*, long long>> q;
        //initially push root node and set its position to 0(0-based indexing)
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            long long leftPos = 0, rightPos = 0;

            //mmin stores the leftmost value of the current level so to minimize the calculaltion numbers by reducing it from col, so that indexing from each level can start from 0
            int mmin = q.front().second;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                long long col = q.front().second - mmin;
                q.pop();
                
                //if i == 0 then leftmost node and if i == n-1 then rightmost node in the lvel
                if(i == 0)
                    leftPos = col;
                if(i == (size-1))
                    rightPos = col;
                
                //if left or right child exist then push it into queue along with it's position, if left cchild then 2*pos+1 else and if right child then 2*i+2
                if(node->left)
                    q.push({node->left, 2*col+1});
                if(node->right)
                    q.push({node->right, 2*col+2});
            }
            //after each level is traversed compare for maxwidth and store it
            maxWidth = max(maxWidth, rightPos-leftPos+1);
        }
        return (int)maxWidth;
    }
};

//T.C : O(n), as in BFS all the nodes are traversedd exactly once
//S.C : O(w), w->width of the tree, as queue will store maximum of w nodes at a time that is nodes in that particular level, in worst case w = n
