// Last updated: 19/12/2025, 19:21:22
class Solution {
public:
    bool pos = true;
    int f(int ind,int val,int n,vector<int>&values,vector<vector<int>>&dp){
        if(ind==n){
            if(val==0) return 1;
            return 0;
        }
        if(dp[ind][val]!=-1) return dp[ind][val];
        int take = 0;
        if(val>=values[ind]) take = f(ind,val-values[ind],n,values,dp);
        int notTake = f(ind+1,val,n,values,dp);
        return dp[ind][val] = take + notTake;
    }
    int find(int val,vector<int>&values){
        vector<vector<int>>dp(values.size(),vector<int>(val+1,-1));
        return f(0,val,values.size(),values,dp);
    }
    vector<int> findCoins(vector<int>& numWays) {
        vector<int>ans={};
        int n = numWays.size();
        for(int i=0;i<n;i++){
            int x = find(i+1,ans);
            if(x<numWays[i]-1 || x>numWays[i]) return {};
            if(x==numWays[i]) continue;
            else ans.push_back(i+1);
        }
        return ans;
    }
};