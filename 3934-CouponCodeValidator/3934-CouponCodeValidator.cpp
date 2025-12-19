// Last updated: 19/12/2025, 19:21:14
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,int>mp={
            {"electronics",0},{"grocery",1},{"pharmacy",2},{"restaurant",3}
        };
        vector<pair<int,string>>pr;
        for(int i=0;i<code.size();i++){
            if(code[i].empty()) continue;
            if(!regex_match(code[i],regex("^[a-zA-Z0-9_]+$"))) continue;
            if(!mp.count(businessLine[i])) continue;
            if(!isActive[i]) continue;
            pr.push_back({mp[businessLine[i]],code[i]});
        }
        sort(pr.begin(),pr.end());
        vector<string>rs;
        for(auto i : pr) rs.push_back(i.second);
        return rs;
    }
};