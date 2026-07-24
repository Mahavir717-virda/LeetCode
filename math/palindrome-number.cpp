class Solution {
public:
    bool isPalindrome(unsigned int x) {
        if (x < 0) return false;  // negative numbers are not palindromes

       unsigned int original = x;
        unsigned int ans = 0;

        while (x > 0) {
            unsigned int last = x % 10;
            ans = ans * 10 + last;
            x /= 10;
        }

        return ans == original;
    }
};
