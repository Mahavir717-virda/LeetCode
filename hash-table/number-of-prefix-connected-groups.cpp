class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> prefixCount;

        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() < k)
                continue;

            string prefix = words[i].substr(0, k);
            prefixCount[prefix]++;
        }

        int groups = 0;

        for (auto it : prefixCount) {
            if (it.second >= 2) {
                groups++;
            }
        }

        return groups;
    }
};