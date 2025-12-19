// Last updated: 19/12/2025, 19:24:01
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<int> alpha(26, 0);
        map<string, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (alpha[j] > 0) {
                        alpha[j]--;
                        string ch(1, 'a' + j); 
                        mp[ch].pop_back();
                        break;
                    }
                }
            } else {
                int xf = s[i] - 'a';
                alpha[xf]++;
                string ch(1, s[i]); 
                mp[ch].push_back(i);
            }
        }

        vector<int> ans(n, 0);
        for (auto i : mp) {
            for (int x = 0; x < i.second.size(); x++) {
                ans[i.second[x]] = 1;
            }
        }

        string ans1 = "";
        for (int i = 0; i < n; i++) {
            if (ans[i] == 1) {
                ans1 += s[i];
            }
        }

        return ans1;
    }
};
