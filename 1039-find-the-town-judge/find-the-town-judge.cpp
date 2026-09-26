class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in_degree(n+1), out_degree(n+1);
        for(auto edge : trust){
            in_degree[edge[1]] += 1;
            out_degree[edge[0]] += 1;
        }

        for(int i = 1; i <= n; i++){
            if(in_degree[i] == n-1 && out_degree[i] == 0)
                return i;
        }
        return -1;
    }
};