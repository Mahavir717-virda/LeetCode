class Solution {
public:
    bool isPalindrom(string ans) {

        int i = 0, j = ans.length() - 1;

        while (i < j) {
            if (ans[i] != ans[j]) {
                return false;
            }

            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length(), maxLen = -1, len = 1, start = -1;
        for(int i = 0; i < n; i++)
        {
            //   This is for strings which are having odd length
            int left = i, right = i;
            while(left >= 0 and right < n and s[left] == s[right])
            {
                left--; right++;
            }
            len = right - left - 1;
            if(len > maxLen)
            {
                maxLen = len;
                start = left + 1;
            }


            //   This is for strings whcih have even length
            left = i; right = i + 1;
            while(left >= 0 and right < n and s[left] == s[right])
            {
                left--; right++;
            }
            len = right - left - 1;
            if(len > maxLen)
            {
                maxLen = len;
                start = left + 1;
            }
        }

        return s.substr(start, maxLen);

    }   
};