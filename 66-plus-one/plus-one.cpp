//self approach
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for(int i = digits.size()-1; i >= 0; i--){
            if(carry == 1){
                carry = (digits[i] == 9) ? 1 : 0;
                digits[i] = (digits[i] == 9) ? 0 : digits[i] + 1;
            }

            if(carry == 0)
                break;
        }

        if(carry == 1)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};