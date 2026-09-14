class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(img1[r][c] == 1)
                    ones1.push_back({r, c});
                if(img2[r][c] == 1)
                    ones2.push_back({r, c});
            }
        }

        map<pair<int, int>, int> mpp;
        int maxOverlap = 0;

        for(auto[r1, c1] : ones1){
            for(auto [r2, c2] : ones2){
                int dr = r1-r2;
                int dc = c1-c2;

                mpp[{dr, dc}]+= 1;
                maxOverlap = max(maxOverlap, mpp[{dr, dc}]);
            }
        }
        return maxOverlap;
    }
};