//optimal lec
class Solution {
    int findLeftHeight(TreeNode* node){
        if(!node)
            return 0;
        
        return 1 + findLeftHeight(node->left);
    }
    int findRightHeight(TreeNode* node){
        if(!node)
            return 0;
        
        return 1 + findRightHeight(node->right);
    }
public:
    int countNodes(TreeNode* root) {
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if(lh == rh)
            return (1 << lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// T.C : O(logn * logn), Calculating leftHeight and rightHeight each takes O(log N) time. In the worst-case scenario, the recursive calls occur at most log N times, leading to a total time complexity of O(logn * logn).
//S.C : O(logn),The maximum depth of the recursion stack is equal to the tree's height, which is log n for a complete binary tree.