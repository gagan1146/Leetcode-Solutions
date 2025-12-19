// Last updated: 19/12/2025, 19:19:52
class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n), ans = "";
        for(auto x:s){
            if(x!='0') ans+=x;
        }
        if(ans.empty()) return 0;
        long long x = stoi(ans), res = 0LL;
        for(auto x:ans) res+=(x-'0');
        return x*res;
    }
};