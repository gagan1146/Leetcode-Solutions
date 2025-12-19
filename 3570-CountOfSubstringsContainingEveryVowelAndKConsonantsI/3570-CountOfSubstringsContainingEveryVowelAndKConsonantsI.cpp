// Last updated: 19/12/2025, 19:23:34
class Solution {
public:
    int countOfSubstrings(string word, int k) {
        string s = "aeiou";
        map<char,int> mp;
        int n = word.length();
        int ans = 0;
        for (int low = 0; low < n; low++) {
            mp.clear();
            int c = 0;
            for (int high = low; high < n; high++) {
                char ch = word[high];
                if (s.find(ch) != string::npos) {
                    mp[ch]++;
                } else {
                    c++;
                }
                if (high - low + 1 >= 5) { 
                    if (mp.size() == 5 && c == k) {
                        ans++;
                    }
                    if (c > k) break;
                }
            }
        }

        return ans;
    }
};