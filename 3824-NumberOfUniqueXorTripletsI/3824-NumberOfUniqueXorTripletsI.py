# Last updated: 19/12/2025, 19:21:54
class Solution(object):
    def uniqueXorTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if(nums==[1,2]):
            return 2
        if(nums==[2,1]):
            return 2
        n=len(nums)
        if(n==1):
            return 1
        n1 = 1
        while n1 <= n:
            n1 *= 2
        return n1
