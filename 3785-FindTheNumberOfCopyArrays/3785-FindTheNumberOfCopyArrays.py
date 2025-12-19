# Last updated: 19/12/2025, 19:22:11
class Solution:
    def countArrays(self, original: List[int], bounds: List[List[int]]) -> int:
        ab = bounds[:]  
        u0, v0 = bounds[0]
        mi, ms = u0, v0
        
        for i in range(1, len(original)):
            diff = original[i] - original[i - 1]
            mi += diff
            ms += diff
            
            u, v = bounds[i]
            mi = max(mi, u)
            ms = min(ms, v)
            
            if mi > ms:
                return 0
        
        return ms - mi + 1