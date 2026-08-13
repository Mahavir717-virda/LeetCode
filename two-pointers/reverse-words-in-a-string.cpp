class Solution {
public:
vector<string> temp;
    string reverseWords(string s) {
        string ans = "";
        stringstream ss(s);
        string token;
        while(ss >> token)
        {
            temp.push_back(token);
        }

        for(int i = temp.size() - 1; i >= 0; i--)
        {
            ans += temp[i];
            if(i != 0)
                ans +=" ";
        }
        return ans;
    }
};