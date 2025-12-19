// Last updated: 19/12/2025, 19:20:46
class Solution {
public:
    int MOD = 1000000007;
    int f(int ind, int n, int parity, int count, vector<int>& nums, vector<vector<vector<int>>>&dp) {
        if (ind == n) return count != 0;
        if(dp[ind][parity+1][count]!=-1) return dp[ind][parity+1][count];
        int take = 0;
        int curParity = nums[ind] % 2;
        if (count == 0 || curParity != parity) {
            take = f(ind + 1, n, curParity, 1, nums, dp);
        }
        else if (count < 2) {
            take = f(ind + 1, n, parity, count + 1, nums, dp);
        }
        int notTake = f(ind + 1, n, parity, count, nums, dp);
        return dp[ind][parity+1][count] = (take + notTake)%MOD;
    }

    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(3,-1)));
        return f(0, n, -1, 0, nums,dp); 
    }
};