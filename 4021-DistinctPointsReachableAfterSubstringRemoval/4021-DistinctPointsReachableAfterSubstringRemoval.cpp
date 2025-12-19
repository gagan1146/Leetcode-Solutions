// Last updated: 19/12/2025, 19:20:47
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<pair<int,int>>pr(n+1),suf(n+1);
        auto mv = [&](char c){
            if(c=='U') return make_pair(0,1);
            if(c=='D') return make_pair(0,-1);
            if(c=='L') return make_pair(-1,0);
            return make_pair(1,0);
        };
        for(int i=0;i<n;i++){
            auto [dx,dy] = mv(s[i]);
            pr[i+1]={pr[i].first+dx,pr[i].second+dy};
        }
        for(int i=n-1;i>=0;i--){
            auto [dx,dy]=mv(s[i]);
            suf[i]={suf[i+1].first+dx,suf[i+1].second+dy};
        }
        set<pair<int,int>>st;
        for(int i=0;i+k<=n;i++){
            int x = pr[i].first+suf[i+k].first;
            int y = pr[i].second+suf[i+k].second;
            st.insert({x,y});
        }
        return st.size();
    }
};