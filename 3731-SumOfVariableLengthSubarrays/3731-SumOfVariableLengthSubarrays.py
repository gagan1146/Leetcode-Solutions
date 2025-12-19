# Last updated: 19/12/2025, 19:22:35
class Solution:
    def subarraySum(self, nums: List[int]) -> int:
        c1=0
        for i in range(len(nums)):
            c=i-nums[i]
            if(c<0):
                c1+=sum(nums[:i+1])
            else:
                c1+=sum(nums[c:i+1])
        return c1