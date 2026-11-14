
class Solution {
public:
    multiset<int> low, high;

    // Maintain sizes and ordering
    void balance() {
        while (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }

        while (low.size() < high.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }

    // Insert an element
    void add(int x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
        }
        else {
            high.insert(x);
        }

        balance();
    }

    // Remove one occurrence
    void remove(int x) {
        auto it = low.find(x);

        if (it != low.end()) {
            low.erase(it);
        }
        else {
            it = high.find(x);
            high.erase(it);
        }

        balance();
    }

    // Get current median
    double getMedian(int k) {
        if (k % 2 == 1) {
            return *low.rbegin();
        }

        return ((long long)*low.rbegin() +
                *high.begin()) / 2.0;
    }

    vector<double> medianSlidingWindow(
        vector<int>& nums, int k) {

        low.clear();
        high.clear();

        vector<double> ans;

        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }

        ans.push_back(getMedian(k));

        for (int i = k; i < nums.size(); i++) {

            // Remove outgoing element
            remove(nums[i - k]);

            // Insert incoming element
            add(nums[i]);

            ans.push_back(getMedian(k));
        }

        return ans;
    }
};
