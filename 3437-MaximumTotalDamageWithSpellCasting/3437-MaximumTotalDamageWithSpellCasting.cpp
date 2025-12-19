// Last updated: 19/12/2025, 19:24:04
class Solution {
public:
    long long f(int ind,vector<int>&power,unordered_map<long long,long long>&mp,int n,vector<long long>&dp){
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        auto it = lower_bound(power.begin(),power.end(),power[ind]+3)-power.begin();
        long long take = power[ind]*mp[power[ind]] + f(it,power,mp,n,dp);
        long long notTake = f(ind+1,power,mp,n,dp);
        return dp[ind] = max(take,notTake);
    }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long,long long>mp;
        for(auto it:power)
        {
            mp[it]++;
        }
        sort(power.begin(),power.end());
        power.erase(unique(power.begin(),power.end()),power.end());
        long long maxi=INT_MIN;
        int n=power.size();
        vector<long long>dp(n+1,-1);
        return f(0,power,mp,n,dp);
    }
};