# Last updated: 19/12/2025, 19:22:25
class Solution:
    def maxDifference(self, s: str) -> int:
        x=Counter(s)
        mini,maxi1=100,0
        for i in x.values():
            if(i%2!=0):
                maxi1=max(maxi1,i)
            else:
                mini=min(mini,i)
        return maxi1-mini