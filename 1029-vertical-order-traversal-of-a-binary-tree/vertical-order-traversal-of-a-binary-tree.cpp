//lec approach bfs postorder
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root)
            return ans;
        
        //queue stores node, vertical, level
        queue<pair<TreeNode*, pair<int, int>>> q;
        //map is usedd to map nodes by mapping nodes with level that with vertical
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> nodes;

        //initially push the root node to the queue to start
        q.push({root, {0, 0}});

        while(!q.empty()){
            //pop the elment at front from queue
            auto elem = q.front();
            q.pop();

            TreeNode* node = elem.first;
            int x = elem.second.first;//vertical
            int y = elem.second.second;//level

            //map node with x and y
            nodes[x][y].push(node->val);

            //if a left child of node exists then push it into the queue and decrease the vertical by 1 and increase the level
            if(node->left)
                q.push({node->left, {x-1, y+1}});

            //if a right child of node exists then push it into the queue and increase the vertical by 1 and increase the level
            if(node->right)
                q.push({node->right, {x+1, y+1}});
        }

        //after all the nodes are traversed, traverse the map and store the vertical order into the answer vector
        for(auto elem : nodes){
            vector<int> temp;
            for(auto it : elem.second){
                while(!it.second.empty()){
                    temp.push_back(it.second.top());
                    it.second.pop();
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//T.C : O(nlogn), O(n) for traversing all the nodes exactly once and O(logn) for priority queue for ordering the nodes, as these operations are happening together thus the complexity is multiplied
//S.C : O(n), O(n) for map, and O(n/2) for queue 