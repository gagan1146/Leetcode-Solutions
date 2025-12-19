// Last updated: 19/12/2025, 19:20:32
class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        vector<int>p(n);
        p[0]=s[0]-'a'+1;
        for(int i=1;i<n;i++) p[i]=p[i-1]+(s[i]-'a'+1);
        for(int i=0;i<n-1;i++)
            if(p[i]==p[n-1]-p[i]) return true;
        return false;
    }
};