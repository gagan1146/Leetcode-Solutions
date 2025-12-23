// Last updated: 23/12/2025, 21:47:29
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int left = n, right = -1, bottom = -1, top = m, x = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    x++;
                    left = min(left,j);
                    right = max(right,j);
                    top = min(top,i);
                    bottom = max(bottom,i);
                }
            }
        }
        if(x==0) return 0;
        return (right-left+1)*(bottom-top+1);
    }
};