# Last updated: 19/12/2025, 19:21:34
class Solution(object):
    def canMakeEqual(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        def f(t):
            c = 0
            a = nums[:]
            for i in range(len(a) - 1):
                if a[i] != t:
                    a[i] *= -1
                    a[i + 1] *= -1
                    c += 1
            return c if a[-1] == t else float('inf')
    
        return min(f(1), f(-1)) <= k