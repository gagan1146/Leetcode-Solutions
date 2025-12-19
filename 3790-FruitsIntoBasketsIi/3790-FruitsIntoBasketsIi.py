# Last updated: 19/12/2025, 19:22:07
class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        ans,n,c=0,len(fruits),0
        vis=[0]*n
        for i in range(n):
            for j in range(n):
                if(vis[j]==0 and fruits[i]<=baskets[j]):
                    vis[j]=1
                    break
        for i in vis:
            if(i==0):
                c+=1
        return c