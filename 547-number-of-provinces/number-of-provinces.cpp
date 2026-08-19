class Solution {
private:
    void bfs(int node, vector<vector<int>>& isConnected, vector<int>& vis){
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i = 0; i < isConnected.size(); i++){
                if(isConnected[node][i] == 1 && !vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis(n, 0);//0 -> unvisited, 1->visited
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt += 1;
                vis[i] = 1;
                bfs(i, isConnected, vis);
            }
        }
        return cnt;
    }
};