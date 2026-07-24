class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (char ch : s) {
            if (isalpha(ch)) {
                if (vowels.count(ch)) {
                    v++;
                } else {
                    c++;
                }
            }
        }
        if(c > 0)
        {
            return v / c;
        }

        return 0;
    }
};