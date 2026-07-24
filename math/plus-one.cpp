class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; // No carry needed, just increment and return
                return digits;
            }
            digits[i] = 0; // If it's 9, it becomes 0 and the loop continues (carry)
        }

        // If the loop finishes, it means we had something like 999 -> 000
        // We need to add a '1' at the very beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};