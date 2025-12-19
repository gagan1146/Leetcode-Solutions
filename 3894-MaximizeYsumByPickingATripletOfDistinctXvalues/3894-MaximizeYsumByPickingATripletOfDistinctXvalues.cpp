// Last updated: 19/12/2025, 19:21:25
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        map<int,int>mp;
        int n = x.size();
        for(int i=0;i<n;i++){
            if(mp.find(x[i])!=mp.end()) mp[x[i]]=max(mp[x[i]],y[i]);
            else mp[x[i]]=y[i];
        }
        vector<int> values;
        for(auto& pair : mp) {
            values.push_back(pair.second);
        }
        
        if(values.size() < 3) return -1;
        
        sort(values.begin(), values.end(), greater<int>());
        return values[0] + values[1] + values[2];
        
    }
};