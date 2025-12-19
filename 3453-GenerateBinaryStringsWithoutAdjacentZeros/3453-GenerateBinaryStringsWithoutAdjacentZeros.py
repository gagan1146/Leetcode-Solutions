# Last updated: 19/12/2025, 19:23:57
class Solution(object):
    def validStrings(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        l = set()
        def gen(t,l):
            if len(t)>=n:
                l.add(t)
                return
            if t[-1] == '0':
                t += '1'
                gen(t,l)
            elif t[-1] == '1':
                gen(t+'0',l)
                gen(t+'1',l)
        gen('0',l)
        gen('1',l)
        return l