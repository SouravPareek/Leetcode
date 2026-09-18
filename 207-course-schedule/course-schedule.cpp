class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjLs(numCourses);
        vector<int> in_degree(numCourses);

        for(auto it : prerequisites){
            adjLs[it[0]].push_back(it[1]);
            in_degree[it[1]] += 1;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in_degree[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt += 1;

            for(int it : adjLs[node]){
                in_degree[it] -= 1;

                if(in_degree[it] == 0)
                    q.push(it);
            }
        }

        return cnt == numCourses;
    }
};