// Last updated: 22/12/2025, 07:56:44
class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(s[i]=='1'){
                ans += pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};