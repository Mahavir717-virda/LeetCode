class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ranges::sort(people);

        int boats = 0, n = people.size();
        int i = 0, j = n - 1;
        //   We will peak greedily 
        while(i <= j)
        {
            if(people[i] + people[j] <= limit)
            {
                //   The heaviest and lightest persons sum is as near as the limit
                //  so then if the lightest persons are remaining then we can send 2 person in one boat 
                boats++;
                i++;
                j--;
            }
            else
            {
               boats++;
               // if both is weighting above the limit then we will send the most heaviest person first rather then the lighest one 
               if(people[j] <= limit)
                j--;
               else 
                i++;
            }
        }
        return boats;
    }
};