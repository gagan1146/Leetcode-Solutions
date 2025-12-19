# Last updated: 19/12/2025, 19:21:57
class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        d1,d2,d3,d4 = {},{},{},{}    
        for x, y in buildings:
            if x not in d1:
                d1[x] = y
                d2[x] = y
            else:
                d1[x] = min(d1[x], y)
                d2[x] = max(d2[x], y)
            if y not in d3:
                d3[y] = x
                d4[y] = x
            else:
                d3[y] = min(d3[y], x)
                d4[y] = max(d4[y], x)
        s = set((x, y) for x, y in buildings)
        ans = 0
        for x, y in buildings:
            if d1[x] < y and d2[x] > y and d3[y] < x and d4[y] > x:
                ans += 1
        return ans