// Last updated: 19/12/2025, 19:20:58
class Solution {
public:
    int f(int ind1, int ind2, int m, int n,vector<vector<int>>&grid, int k,vector<vector<vector<int>>>&dp){
        if(ind1==m-1 && ind2==n-1){
            if(k>0){
                return grid[m-1][n-1];
            }
            if(grid[m-1][n-1]==0) return 0;
            return -1e9;
        }
        if(ind1>=m || ind1<0 || ind2<0 || ind2>=n || k<0) return -1e9;
        if(dp[ind1][ind2][k]!=-1) return dp[ind1][ind2][k];
        int take = -1e9;
        if(grid[ind1][ind2]==0) take = max(f(ind1+1,ind2,m,n,grid,k,dp),f(ind1,ind2+1,m,n,grid,k,dp));
        else if(grid[ind1][ind2]==1 && k>0){
            take = max(take,1+max(f(ind1+1,ind2,m,n,grid,k-1,dp),f(ind1,ind2+1,m,n,grid,k-1,dp)));
        }
        else if(grid[ind1][ind2]==2 && k>0){
            take = max(take, 2+max(f(ind1+1,ind2,m,n,grid,k-1,dp),f(ind1,ind2+1,m,n,grid,k-1,dp)));
        }
        return dp[ind1][ind2][k] = take;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n=grid[0].size();
        int ans = 0;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        ans = f(0,0,m,n,grid,k,dp);
        return max(-1,ans);
    }
};