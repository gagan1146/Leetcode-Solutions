# Last updated: 19/12/2025, 19:21:48
class Solution:
    def minCosts(self, cost: List[int]) -> List[int]:
        x=cost[0]+1
        ans=[]
        for i in cost:
            if(x>i):
                ans.append(i)
                x=i
            else:
                ans.append(x)
        return ans