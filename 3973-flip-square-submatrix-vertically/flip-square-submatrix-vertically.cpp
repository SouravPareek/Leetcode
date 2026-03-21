//self solution
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int x_limit = x+k-1;
        int y_limit = y+k-1;

        while(x < x_limit){
            for(int i = y; i <= y_limit; i++)
                swap(grid[x][i], grid[x_limit][i]);
            
            x += 1;
            x_limit -= 1;
        }
        return grid;
    }
};