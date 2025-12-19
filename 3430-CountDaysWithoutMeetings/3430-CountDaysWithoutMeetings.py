# Last updated: 19/12/2025, 19:24:06
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        c,maxi=0,0
        for i,j in meetings:
            if(maxi<i):
                c+=(i-maxi-1)
            maxi=max(maxi,j)
        c+=(days-maxi)
        return c