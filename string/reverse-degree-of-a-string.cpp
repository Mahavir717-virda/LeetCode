class Solution {
public:
    int reverseDegree(string s) {
        map<char,int> mp;
        int val = 26;
        for(int i = 97; i < 123; i++)
        {
            mp[(char)i] = val;
            val--;
        }

        for(auto it : mp)
        {
           cout << it.first <<  " " << it.second << endl;
        }

        int sum = 0;

        for(int i = 0; i < s.size(); i ++)
        {
            sum += (mp[s[i]] * (i + 1));
        }
        return sum;
    }
};