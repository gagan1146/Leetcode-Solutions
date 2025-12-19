// Last updated: 19/12/2025, 19:20:33
class Solution {
public:
    long long removeZeros(long long n) {
        long long res = 0;
        string s = to_string(n);
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') continue;
            res = res * 10 + (s[i]-'0');
        }
        return res;
    }
};