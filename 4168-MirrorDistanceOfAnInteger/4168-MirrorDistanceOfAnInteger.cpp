// Last updated: 22/12/2025, 07:56:33
class Solution {
public:
    int mirrorDistance(int n) {
        string x = to_string(n);
        reverse(x.begin(),x.end());
        int n1 = stoi(x);
        return abs(n-n1);
    }
};