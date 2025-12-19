# Last updated: 19/12/2025, 19:23:33
class Solution(object):
    def maxGoodNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        binaries = [bin(num)[2:] for num in nums]
        
        from itertools import permutations
        
        max_number = 0
        for perm in permutations(binaries):
            combined_binary = ''.join(perm)
            number = int(combined_binary, 2)
            max_number = max(max_number, number)
        
        return max_number

