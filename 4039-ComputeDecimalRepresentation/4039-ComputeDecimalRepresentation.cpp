// Last updated: 19/12/2025, 19:20:41
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        string s = to_string(n);
        int len=s.size();
        int pow1 = pow(10,len-1);
        for (int i = 0; i < len; i++) {
            int digit = s[i] - '0';
            if (digit != 0) {
                int placeValue = digit * pow1;
                ans.push_back(placeValue);
            }
            pow1/=10;
        }
        return ans;
    }
};