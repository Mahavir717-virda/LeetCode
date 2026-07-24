class Solution {
public:
    string reverseByType(string s) {
        
    string letters = "", specials = "";

    for (char c : s) {
        if (c >= 'a' && c <= 'z')
            letters += c;
        else
            specials += c;
    }

    reverse(letters.begin(), letters.end());
    reverse(specials.begin(), specials.end());

    int l = 0, sp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = letters[l++];
        else
            s[i] = specials[sp++];
    }
        return s;
    }
};