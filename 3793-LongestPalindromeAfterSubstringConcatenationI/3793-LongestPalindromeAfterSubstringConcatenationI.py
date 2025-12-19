# Last updated: 19/12/2025, 19:22:05
class Solution:
    def is_p(self, s: str) -> bool:
        return s == s[::-1]

    def longestPalindrome(self, s: str, t: str) -> int:
        ml = 0
        
        for i in range(len(s) + 1):
            for j in range(i, len(s) + 1):
                sub_s = s[i:j]
                
                for k in range(len(t) + 1):
                    for l in range(k, len(t) + 1):
                        sub_t = t[k:l]
                        
                        cd = sub_s + sub_t
                        if self.is_p(cd):
                            ml = max(ml, len(cd))
        
        return ml
