//self bfs(level-order)

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(!root)
            return ans;

        //BFS queue: stores (node, level)
        queue<pair<TreeNode*, int>> q;

        //map[level] = latest node value seen at that level, using map keeps levels ordered (0,1,2,...) so we can iterate later
        map<int, int> mpp;

        //start BFS from root at level 0
        q.push({root, 0});

        //if q is empty stop the loop
        while(!q.empty()){
            //take the front element
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;

            //Overwrite value for this level. In BFS left-to-right order, the rightmost node at that level will be processed last, so it will overwrite previous values for the same level.
            mpp[p.second] = node->val;
            
            //push children with level+1
            if(node->left)
                q.push({node->left, p.second + 1});
            if(node->right)
                q.push({node->right, p.second + 1});
        }

        //now push all the nodes val for each level from map which stores the rightmost elment
        for(auto p : mpp){
            ans.push_back(p.second);
        }

        return ans;
    }
};

//T.C = O(nlogh), as traversing all the elments using queue will take at most O(n) and also at each iteration map will take O(logh) for assignment, and O(h) for storing map elments into the ans vector, in worst case h = n(skewed tree)
//S.C = O(n), as in map will take O(h) space , where h = n  in worst case like skewed tree and queue will take O(w) w->tree width 