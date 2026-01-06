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
class BSTIterator {
private:
	stack<TreeNode*> st;
    bool reverse;

    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            node = (reverse) ? node->right : node->left;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
		pushAll(root);
	}

    bool hasNext() {
		return !st.empty();
	}

    int next() {
		TreeNode* temp = st.top();
        st.pop();
        if(reverse)
            pushAll(temp->left);
        else
            pushAll(temp->right);

        return temp->val;
	}
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next(), j = r.next();

        while(i < j){
            if(i + j == k)
                return true;
            else if(i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};