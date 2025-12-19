// Last updated: 19/12/2025, 19:21:47
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        stack<int>st;
        for(int i: nums){
            while(!st.empty() && i<st.top()) st.pop();
            if(st.empty() || i>st.top()){
                if(i>0) ans++;
                st.push(i);
            }
        }
        return ans;
    }
};