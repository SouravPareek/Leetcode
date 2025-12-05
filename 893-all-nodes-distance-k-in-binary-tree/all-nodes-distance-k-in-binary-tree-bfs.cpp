//lec + self code BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    //function to map nodes with thier parent
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentMap){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            //if node's left child exist then map it to its parent and then push it in to the queue
            if(node->left){
                parentMap[node->left] = node;
                q.push(node->left);
            }

            ////if node's right child exist then map it to its parent and then push it in to the queue
            if(node->right){
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        if(!root)
            return ans;
        
        unordered_map<TreeNode*, TreeNode*> parentMap;

        findParent(root, parentMap);

        //to track if any of the nodes are visited or not, set is used to avoid duplicate entries into the set
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        //mark target elment as visited as we will start with it
        visited.insert(target);
        q.push(target);

        int dist = 0;

        while(!q.empty()){
            //if iterations becomes equal to k meansall the nodes at distance k are found thus break the loop
            if(dist == k)
                break;

            int size = q.size();
            
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                //if node's left child exist and is not visited then push it into the queue and mark as visited
                if(node->left && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }

                //if node's right child exist and is not visited then push it into the queue and mark as visited
                if(node->right && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                //if node's parent exist and is not visited then push it into the queue and mark as visited
                if(parentMap.find(node) != parentMap.end() && visited.find(parentMap[node]) == visited.end()){
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            //after each iteration increment distance by 1
            dist += 1;
        }

        //once k iterations are done the remaining nodes in the queue are at distance of k from target thus these are the answers so push them into the ans and return ans
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

//T.C : O(n), Traversing the tree to create the parent hashmap requires visiting each node once (O(N)), exploring all nodes at a distance of 'K' in the worst case is O(N), and the logarithmic lookup time for the hashmap is O(log N). Therefore, the overall time complexity simplifies to O(N).
//S.C : O(n),  The space complexity is determined by the data structures used: O(N) for the parent hashmap, O(N) for the DFS queue, and O(N) for the visited hashmap. Thus, the total space complexity is O(N).
