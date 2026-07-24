class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> Freq;

        for (int i = 0; i < text.length(); i++) {
            Freq[text[i]]++;
        }

        int b = Freq['b'];
        int a = Freq['a'];
        int l = Freq['l'] / 2;
        int o = Freq['o'] / 2;
        int n = Freq['n'];

        return min({b, a, l, o, n});
    }
};