// Last updated: 19/12/2025, 19:22:17
class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string ans;
            int n = s.length() - 1;
            ans.reserve(n);
            for (int i = 0; i < n; i++) {
                int a = s[i] - '0';
                int b = s[i + 1] - '0';
                ans.push_back(((a + b) % 10) + '0');
            }
            s = ans;
        }
        return s.length() == 2 && s[0] == s[1];
    }
};