using namespace std;
class Solution {

public:
    string sortVowels(string s) {
        vector<int> freq(26 * 2, 0);

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                freq[c - 'A']++;
            } else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
                       c == 'u') {
                freq[c - 'a' + 26]++;
            }
        }

        string ans = "";
        int vowelptr = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' &&
                c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
                ans += c;
            } else {
                while (freq[vowelptr] == 0) {
                    vowelptr++;
                }
                char sortedVowel;
                if (vowelptr < 26) {
                    sortedVowel = 'A' + vowelptr;
                } else {
                    sortedVowel = 'a' + (vowelptr - 26);
                }
                ans += sortedVowel;
                freq[vowelptr]--;
            }
        }
        return ans;
    }
};