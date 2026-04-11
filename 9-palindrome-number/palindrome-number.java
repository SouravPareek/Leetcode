class Solution {
    public boolean isPalindrome(int x) {
        int reversed = 0;
        int remainder = 0;
        int original = x;

        while(x > 0){
            remainder = x%10;
            reversed = reversed*10 + remainder;
            x /= 10;
        }
        return original == reversed;
    }
}