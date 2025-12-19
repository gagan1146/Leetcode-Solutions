// Last updated: 19/12/2025, 19:20:11
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        string ans = "";
        for(int i=0;i<num;i++){
            int d = min(9,sum);
            ans+=char('0'+d);
            sum-=d;
        }
        return ans;
    }
};