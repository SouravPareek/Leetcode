class Solution {
private:
    void leftRotate(vector<int>& arr, int k) {
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());
    }
    void rightRotate(vector<int>& arr, int k) {
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
    }

public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> original = mat;
        int n = mat.size();
        int m = mat[0].size();

        k = k%m;

        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                leftRotate(mat[j], k);
            } else {
                rightRotate(mat[j], k);
            }
        }
        return mat == original;
    }
};