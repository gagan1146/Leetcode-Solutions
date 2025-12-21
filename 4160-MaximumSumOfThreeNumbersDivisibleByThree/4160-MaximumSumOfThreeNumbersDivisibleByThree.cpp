// Last updated: 21/12/2025, 07:25:15
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>b[3];
        for(auto x:nums) b[x%3].push_back(x);
        for(int i=0;i<3;i++) sort(b[i].rbegin(),b[i].rend());
        long long r = 0;
        if(b[0].size()>=3) r = max(r,(long long)b[0][0]+b[0][1]+b[0][2]);
        if(b[1].size()>=3) r = max(r,(long long)b[1][0]+b[1][1]+b[1][2]);
        if(b[2].size()>=3) r = max(r,(long long)b[2][0]+b[2][1]+b[2][2]);
        if(b[0].size()>=1&&b[1].size()>=1&&b[2].size()>=1) r = max(r, (long long)b[0][0]+b[1][0]+b[2][0]);
        return r;
    }
};