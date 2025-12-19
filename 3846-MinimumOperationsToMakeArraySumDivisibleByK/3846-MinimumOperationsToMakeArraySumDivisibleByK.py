# Last updated: 19/12/2025, 19:21:42
class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        x=sum(nums)
        if(x%k==0):
            return 0
        else:
            return x%k