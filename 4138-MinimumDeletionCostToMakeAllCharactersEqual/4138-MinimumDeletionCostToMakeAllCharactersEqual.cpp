// Last updated: 22/12/2025, 07:56:40
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        map<char,long long>mp;
        int n = cost.size();
        long long sumi = accumulate(cost.begin(),cost.end(),0LL),maxi=0;
        for(int i=0;i<n;i++){
            mp[s[i]]+=(cost[i]);
        }
        for(auto it:mp){
            maxi = max(maxi,it.second);
        }
        return sumi-maxi;
    }
};