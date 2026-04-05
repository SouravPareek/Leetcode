class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> hash(4);
        //0->left, 1->right, 2->up, 3->down

        for(char ch : moves){
            if(ch == 'L')
                hash[0] += 1;
            else if(ch == 'R')
                hash[1] += 1;
            else if(ch == 'U')
                hash[2] += 1;
            else if(ch == 'D')
                hash[3] += 1;
        }
        if(hash[0] == hash[1] && hash[2] == hash[3])
            return true;
        return false;
    }
};