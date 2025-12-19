# Last updated: 19/12/2025, 19:21:58
class Solution(object):
    def smallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        d = Counter(s)
        m = ""
        l = []

        for c in sorted(d):
            if d[c] % 2 == 1 and (m == "" or c < m):
                m = c
            l.append(c * (d[c] // 2))
        
        h = ''.join(l)
        return h + m + h[::-1]
