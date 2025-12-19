# Last updated: 19/12/2025, 19:22:16
class Solution:
    def maximumMedianSum(self, nums: List[int]) -> int:
        nums.sort()
        n=len(nums)
        ans=0
        t=n//3
        for i in range(n-2,-1,-2):
            ans+=nums[i]
            t-=1
            if(t==0):
                return ans
        return ans