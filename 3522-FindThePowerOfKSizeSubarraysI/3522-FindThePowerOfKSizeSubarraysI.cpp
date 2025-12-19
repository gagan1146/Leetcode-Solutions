// Last updated: 19/12/2025, 19:23:44
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        vector<int>v;
        for(int i=0;i<=nums.size()-k;i++){
            int x=nums[i],f=0;
            for(int j=i+1;j<i+k;j++){
                if(x+1==nums[j]) x=nums[j];
                else{
                    f=1;
                    v.push_back(-1);
                    break;
                }
            }
            if(f!=1) v.push_back(x);
        }
        return v;
    }
};