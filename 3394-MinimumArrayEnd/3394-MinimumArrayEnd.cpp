// Last updated: 19/12/2025, 19:24:10
class Solution {
public:
    long long minEnd(int n, int x) {
        // int r1;
        // vector<int>nums;
        // while(x>0){
        //     c++;
        //     x>>1;
        // }
        // r1=1<<x;
        // nums.push_back(r1);
        bitset<64> X(x), N(n-1), ans=0;
        for(int i=0, j=0; i<56; i++){
            ans[i]=(X[i])?1:N[j++];
        }
        return ans.to_ullong();
    }
};