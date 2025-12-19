// Last updated: 19/12/2025, 19:20:08
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a = 0, b = 0, n = s.length();
        for(auto it:s){
            if(it=='a') a++;
            else b++;
        }
        return n - (min(a,b)*2);
    }
};