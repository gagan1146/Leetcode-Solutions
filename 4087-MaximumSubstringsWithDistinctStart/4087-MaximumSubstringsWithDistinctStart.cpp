// Last updated: 19/12/2025, 19:20:09
class Solution {
public:
    int maxDistinct(string s) {
        map<char,int>mp;
        for(auto it:s) mp[it]=1;
        return mp.size();
    }
};