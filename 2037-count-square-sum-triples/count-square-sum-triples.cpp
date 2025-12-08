//self
class Solution {
public:
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t seed = v.size();
            for (int i : v) {
                seed ^= hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
    int countTriples(int n) {
        unordered_set<vector<int>, VectorHash> st;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = max(i, j); k <= n; k++){
                    if((i*i)+(j*j)-(k*k) == 0){
                        st.insert({i, j, k});
                    }
                }
            }
        }
        return st.size();
    }
};