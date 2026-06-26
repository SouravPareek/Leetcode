class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int, int> mpp;

        for(int it : digits){
            mpp[it] += 1;
        }

        int a, b, c;

        for(int i = 100; i <= 999; i+=2){
            int num = i;
            a = num%10;
            num /= 10;
            b = num%10;
            num /= 10;
            c = num%10;

            bool flag_a = false, flag_b = false, flag_c = false;

            if(mpp[a] > 0){
                mpp[a] -= 1;
                flag_a = true;
            }

            if(mpp[b] > 0){
                mpp[b] -= 1;
                flag_b = true;
            }

            if(mpp[c] > 0){
                mpp[c] -= 1;
                flag_c = true;
            }

            if(flag_a){
                mpp[a] += 1;
            }
            if(flag_b){
                mpp[b] += 1;
            }
            if(flag_c){
                mpp[c] += 1;
            }

            if(flag_a && flag_b && flag_c){
                ans.push_back(i);
            }
        }
        return ans;
    }
};