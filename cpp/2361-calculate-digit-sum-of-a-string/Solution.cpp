class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k)
        {
            string new_s = "";
            for(int i = 0; i < s.size(); i = i + k)
            {
                string str = s.substr(i , k);
                int sum = 0;
                for(auto ch : str)
                {
                    sum += (ch - '0');
                }
                
                new_s += to_string(sum);
            }

            s = new_s;
        }
        return s;
    }
};