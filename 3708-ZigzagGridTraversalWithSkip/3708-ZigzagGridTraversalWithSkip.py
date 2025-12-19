# Last updated: 19/12/2025, 19:22:38
class Solution:
    def zigzagTraversal(self, grid: List[List[int]]) -> List[int]:
        n=len(grid)
        n1=len(grid[0])
        arr=[]
        for i in range(n):
            if(i%2==0):
                for j in range(0,n1,2):
                    arr.append(grid[i][j])
            else:
                if(n1%2==0):
                    for j in range(n1-1,-1,-2):
                        arr.append(grid[i][j])
                else:
                    for j in range(n1-2,-1,-2):
                        arr.append(grid[i][j])
        return arr