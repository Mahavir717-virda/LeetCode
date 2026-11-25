class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        while (n) {
            if (n % 3 == 0 and n % 5 == 0) {
                ans.push_back("FizzBuzz");
            } else if (n % 3 == 0) {
                ans.push_back("Fizz");
            } else if (n % 5 == 0) {
                ans.push_back("Buzz");
            } else {
                ans.push_back(to_string(n));
            }
            n--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};