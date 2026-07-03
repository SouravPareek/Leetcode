class Solution {
private:
    void dfs(vector<vector<int>>& adjLs, vector<int>& vis, int stone){
        vis[stone] = 1;

        for(int neighbor : adjLs[stone]){
            if(!vis[neighbor]){
                dfs(adjLs, vis, neighbor);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adjLs(n);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int cnt = 0;

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adjLs, vis, i);
                cnt += 1;
            }
        }

        return n-cnt;
    }
};