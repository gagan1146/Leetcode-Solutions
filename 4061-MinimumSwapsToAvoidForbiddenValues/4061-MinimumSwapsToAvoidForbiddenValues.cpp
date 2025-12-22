// Last updated: 22/12/2025, 07:57:01
class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        map<int,int>mp,mp2,mp1;
        int n = nums.size(), ans = 0, c = 0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            mp1[forbidden[i]]++;
            if(mp.find(forbidden[i])!=mp.end() && (mp[forbidden[i]]+mp1[forbidden[i]])>n){
                ans=-1;
                break;
            }
            if(mp1.find(nums[i])!=mp1.end() && (mp[nums[i]]+mp1[nums[i]])>n){
                ans=-1;
                break;
            }
            if(nums[i]==forbidden[i]){
                c++;
                mp2[nums[i]]++;
            }
        }
        if(ans==-1) return -1;
        if(c==0) return 0;
        vector<int>pos;
        for(auto it:mp2) pos.push_back(it.second);
        sort(pos.rbegin(),pos.rend());
        int i=0,j=1,res=0;
        while(i<pos.size() && j<pos.size()){
            if(pos[i]<pos[j]){
                res+=pos[i];
                pos[j]-=pos[i];
                i=j;
                j=i+1;
            }
            else if(pos[i]==pos[j]){
                res+=pos[i];
                i=j+1;
                j=i+1;
            }
            else if(pos[j]<pos[i]){
                pos[i]-=pos[j];
                res+=pos[j];
                j++;
            }
        }
        if(i<pos.size()) res += pos[i];
        // if(j<pos.size()) res += pos[j];
        return res;
    }
};