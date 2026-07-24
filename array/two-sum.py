class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Map to store: {value: index}
        seen = {}
        
        for i, num in enumerate(nums):
            # Calculate the required value to reach the target
            complement = target - num
            
            # Check if the complement is already in our map
            if complement in seen:
                return [seen[complement], i]
            
            # Store the current number and its index in the map
            seen[num] = i
            
        return [-1, -1]
