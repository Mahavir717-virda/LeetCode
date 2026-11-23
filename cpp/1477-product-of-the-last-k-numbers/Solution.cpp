class ProductOfNumbers {
public:
    //  This is brute Force Approach 
    vector<int> nums;
    ProductOfNumbers() { nums = {1}; }

    void add(int num) { nums.push_back(num); }

    int getProduct(int k) {
        int product = 1, n = nums.size();
        for (int i = n - 1; i >= n - k; i--) {
            product *= nums[i];
        }

        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */