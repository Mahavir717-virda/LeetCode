class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long ans = 0;
        //   This simple greedy approach based on example
        if (cost1 + cost2 <= costBoth) {
            ans = (1LL * cost1 * need1) + (1LL * cost2 * need2);
        } else {
            // if cost of both < cost1 + cost2   then we will take as much as both possible and then we will check whichever is minimum with respect cost for individual and costBoth that much we will add 
            long long both = min(need1, need2);
            ans = (long long) (both * costBoth);
            
            need1 -= both;
            need2 -= both;

            if (need1 > 0) {
                ans +=  1LL * need1 *  min(cost1, costBoth);
            } else if (need2 > 0) {
                ans += 1LL * need2 *  min(cost2, costBoth);
            }
        }
        return ans;
    }
};