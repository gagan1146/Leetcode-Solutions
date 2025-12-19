// Last updated: 19/12/2025, 19:20:31
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int>mp;
        for(auto x:s) mp[x]++;
        unordered_map<int,vector<char>>gp;
        for(auto &p:mp){
            gp[p.second].push_back(p.first);
        }
        int ans = 0 , fq = 0;
        vector<char>bg;
        for(auto &g: gp){
           int a = g.first, b = g.second.size();
            if(b>ans || (b==ans && a>fq)){
                ans = b;
                fq=a;
                bg=g.second;
            }
        }
        string res;
        for(auto x: bg) res.push_back(x);
        return res;
    }
};