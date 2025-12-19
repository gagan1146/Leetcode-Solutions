// Last updated: 19/12/2025, 19:23:23
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>res;
        int n = nums.size();
        for(int i=0;i<n-k+1;i++){
            priority_queue<pair<int, int>> pq;
            unordered_map<int,int>mp;
            for(int j=i;j<min(i+k,n);j++){
                mp[nums[j]]++;
            }
            for(auto it:mp){
                pq.push({it.second,it.first});
            }
            int x1 = 0, ans = 0;
            while(!pq.empty()){
                if(x1<x) ans += pq.top().first * pq.top().second;
                x1++;
                pq.pop();
            }
            res.push_back(ans);
        }
        return res;
    }
};