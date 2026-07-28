class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
         n = len(nums)
        
        # Outer loop picks the first element
        for i in range(n):
            # Inner loop picks the second element, starting right after i
            for j in range(i + 1, n):
                # If the pair matches the target, return their indices
                if nums[i] + nums[j] == target:
                    return [i, j]
        
        # Return an empty list if no solution is found
        return [-1,-1]