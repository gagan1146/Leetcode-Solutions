# Last updated: 19/12/2025, 19:22:41
class Solution:
    def lcm(self, a, b):
        return a * b // math.gcd(a, b)

    def maxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mxi = 0
        n = len(nums)
        
        for i in range(n):
            for j in range(i + 1, n + 1):
                arr = nums[i:j]
                product = functools.reduce(lambda x, y: x * y, arr)
                a_lcm = functools.reduce(self.lcm, arr)
                a_gcd = functools.reduce(math.gcd, arr)
                
                if product == (a_lcm * a_gcd):
                    mxi = max(mxi, j - i)
        
        return mxi