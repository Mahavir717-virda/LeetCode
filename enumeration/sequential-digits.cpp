class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";

        for(int len = 2; len < 10; len++)
        {
            for(int start = 0; start <= s.length() - len; start++)
            {
                int digit = stoi(s.substr(start,len));
                if(digit >= low && digit <= high)
                    ans.push_back(digit);
            }
        }

        return ans;
    }
};