# Last updated: 19/12/2025, 19:23:48
class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        result = 0
        
        # Count how many valid substrings end at each position
        for i in range(n):
            count = {}
            for j in range(i, n):
                count[s[j]] = count.get(s[j], 0) + 1
                if count[s[j]] >= k:
                    result += n - j  # Count all substrings from i to the end
                    break  # No need to check further, since we need at least one char with k occurrences

        return result
