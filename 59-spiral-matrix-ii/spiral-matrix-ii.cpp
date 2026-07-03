class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n-1;
        int top = 0, btm = n-1;
        int cnt = 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        while(left <= right && top <= btm){
            for(int i = left; i <= right; i++){
                matrix[top][i] = cnt;
                cnt += 1;
            }
            top += 1;

            for(int i = top; i <= btm; i++){
                matrix[i][right] = cnt;
                cnt += 1;
            }
            right -= 1;

            if(left <= right){
                for(int i = right; i >= left; i--){
                    matrix[btm][i] = cnt;
                    cnt += 1;
                }
                btm -= 1;
            }

            if(top <= btm){
                for(int i = btm; i >= top; i--){
                    matrix[i][left] = cnt;
                    cnt += 1;
                }
                left += 1;
            }
        }
        return matrix;
    }
};