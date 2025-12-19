# Last updated: 19/12/2025, 19:24:17
class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        d = {}
        for i in word:
            d[i] = d.get(i, 0) + 1
        l = [i for i in d.values()]
        l.sort()
        n = len(l)
        ans = float('inf')
        for i in range(n):
            c = 0
            target = l[i]
            for j in range(n):
                if l[j] < target:
                    c += l[j]
                elif l[j] > target + k:
                    c += l[j] - (target + k)
            ans = min(ans, c)
        return ans