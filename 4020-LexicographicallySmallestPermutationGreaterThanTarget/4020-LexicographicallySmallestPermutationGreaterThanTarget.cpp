// Last updated: 19/12/2025, 19:20:48
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.size();
        multiset<char> availableChars(s.begin(), s.end());
        int latestDiff = -1;
        for (int i = 0; i < n; i++) {
            if (*availableChars.rbegin() < target[i]) break;
            if (*availableChars.rbegin() > target[i]) latestDiff = i;
            if (availableChars.count(target[i])) {
                availableChars.erase(availableChars.find(target[i]));
            }
            else break;
        }
        if (latestDiff == -1) return "";
        multiset<char> solChars(s.begin(), s.end());
        string res(n, ' ');
        for (int i = 0; i < latestDiff; i++) {
            res[i] = target[i];
            solChars.erase(solChars.find(target[i]));
        }
        auto firstBigger = solChars.upper_bound(target[latestDiff]);
        res[latestDiff] = *firstBigger;
        solChars.erase(firstBigger);
        for (int i = latestDiff + 1; i < n; i++) {
            res[i] = *solChars.begin();
            solChars.erase(solChars.begin());
        }
        return res;
    }
};