//self BFS
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
//function to map nodes with thier parent
    TreeNode* findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentMap, int start){
        TreeNode* target = new TreeNode(-1);

        if(!root)
            return target;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start)
                target = node;

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
        return target;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentMap;

        TreeNode* initial = findParent(root, parentMap, start);


        //to track if any of the nodes are visited or not, set is used to avoid duplicate entries into the set
        unordered_set<TreeNode*> visited;

        queue<TreeNode*> q;

        //mark target elment as visited as we will start with it
        visited.insert(initial);
        q.push(initial);

        int time = 0;
        bool isInfected = false;

        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                //if node's left child exist and is not visited then push it into the queue and mark as visited
                if(node->left && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                    isInfected = true;
                }

                //if node's right child exist and is not visited then push it into the queue and mark as visited
                if(node->right && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                    isInfected = true;
                }

                //if node's parent exist and is not visited then push it into the queue and mark as visited
                if(parentMap.find(node) != parentMap.end() && visited.find(parentMap[node]) == visited.end()){
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                    isInfected = true;
                }
            }
            if(isInfected)
                time += 1;
            isInfected = false;
        }
        return time;
    }
};

//T.C : O(n), where n is the number of nodes in the tree, due to BFS traversals

//S.C : O(n), for storing the parent mapping and the visited set.