# Last updated: 19/12/2025, 19:23:39
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for i in range(k):
            x=min(nums)
            y=nums.index(x)
            nums[y]=nums[y]*multiplier
        return nums