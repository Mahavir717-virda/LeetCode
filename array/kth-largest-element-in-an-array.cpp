class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap declaration: stores elements in ascending order
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for (int num : nums) {
            min_heap.push(num);
            
            // If the heap size exceeds k, pop the smallest element
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        
        return min_heap.top();
    }
};
