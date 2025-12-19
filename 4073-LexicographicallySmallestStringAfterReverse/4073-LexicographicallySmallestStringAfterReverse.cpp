// Last updated: 19/12/2025, 19:20:19
class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        vector<string>v;
        for(int i=1;i<=n;i++) v.push_back(string(s.rbegin()+n-i,s.rend())+s.substr(i));
        for(int i=1;i<=n;i++) v.push_back(s.substr(0,n-i)+string(s.rbegin(),s.rbegin()+i));
        return *min_element(v.begin(),v.end());
    }
};