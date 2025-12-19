// Last updated: 19/12/2025, 19:20:45
class Solution {
public:
    // int f(int ind, int n, vector<int>& nums, int x, vector<unordered_map<int,int>>& dp) {
    //     if (ind == n) {
    //         if (x > 0) return 0;
    //         else return -1e9;
    //     }
    //     if (dp[ind].count(x)) return dp[ind][x];
    //     int take = 1 + f(ind + 1, n, nums, x ^ nums[ind], dp);
    //     int notTake = f(ind + 1, n, nums, x, dp);
    //     return dp[ind][x] = max(take, notTake);
    // }

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size(),c=0,x=0;
        for(auto it:nums){
            if(it==0) c++;
            x=x^it;
        }
        if(x==0){
            if(c==n) return 0;
            return n-1;
        }
        return n;
    }
};