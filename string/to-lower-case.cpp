class Solution {
public:
    string toLowerCase(string s) {
        map<char,char> mp;
        int ch = 97;
        for(int i = 65; i <= 91; i++)
        {
            mp[char(i)] = char(ch);
            ch++;
        }

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'a' and s[i] <= 'z')
                continue;

            if((int)s[i] >= 65 and (int)s[i] <= 90)
                s[i] = mp[s[i]];
        }

        return s;
    }
};