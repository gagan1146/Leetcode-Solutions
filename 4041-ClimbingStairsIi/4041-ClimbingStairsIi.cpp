// Last updated: 19/12/2025, 19:20:40
class Solution {
public:
    int f(int ind,int n,vector<int>&costs,vector<int>&dp){
        if(ind>=n+1) return 1e9;
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take = 1e9;
        for(int i=ind+1;i<=min(ind+3,n);i++){
            take = min(take, f(i,n,costs,dp) + costs[i-1] + (i-ind)*(i-ind));
        }
        return dp[ind] = take;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return f(0,n,costs,dp);
    }
};