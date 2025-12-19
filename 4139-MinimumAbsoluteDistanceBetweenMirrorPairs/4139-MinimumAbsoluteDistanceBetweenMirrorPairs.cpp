// Last updated: 19/12/2025, 19:19:44
class Solution {
public:
    string Reverse(int num) {
        while (num > 0 && num % 10 == 0)
            num /= 10;
        string s = to_string(num);
        reverse(s.begin(), s.end());
        return s;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<string, int> seen;
        int mini = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            string rev = Reverse(nums[i]), rev1 = to_string(nums[i]);
            if (seen.count(rev1)) {
                mini = min(mini, i - seen[rev1]);
            }
            seen[rev] = i;
        }
        return (mini == nums.size() ? -1 : mini);
    }
};