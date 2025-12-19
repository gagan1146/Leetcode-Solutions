// Last updated: 19/12/2025, 19:20:50
class Solution {
public:
    string removeSubstring(string s, int k) {
        string result;
        for (char ch : s) {
            result.push_back(ch);
            if (result.size() >= 2 * k) {
                bool match = true;
                for (int i = 0; i < k; i++) {
                    if (result[result.size() - 1 - i] != ')') {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    for (int i = 0; i < k; i++) {
                        if (result[result.size() - 1 - k - i] != '(') {
                            match = false;
                            break;
                        }
                    }
                }
                if (match) {
                    for (int i = 0; i < 2 * k; i++)
                        result.pop_back();
                }
            }
        }
        return result;
    }
};