// Last updated: 19/12/2025, 19:23:51
class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, n = s.length(), ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ones++;
            if(s[i]=='0'){
                if(i>0 && s[i-1]=='0') continue;
                else ans += ones;
            }
        }
        return ans;
    }
};