class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        unordered_map<char, int> m;
        unordered_map<int, char> m2;
        

        int val = 97;
        for (int i = 0; i < 26; i++) {
            char c = char(val);
            m[c] = weights[i];
            val++;
        }
        
        int val1 = 122;
        for (int i = 0; i < 26; i++) {
            char c = char(val1);
            m2[i] = c;
            val1--;
        }

        
        for (int i = 0; i < words.size(); i++) {
            int sum = 0;
            int weight = 0;
            string str = words[i];
            for (int j = 0; j < words[i].size(); j++) {
                char c = str[j];

                if (m.find(c) != m.end()) {
                    sum += m[c];
                }
            }

            int sol = sum % 26;
            if (m2.find(sol) != m2.end()) {
                    ans += m2[sol];
                }
        }
        return ans;
    }
};