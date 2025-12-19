// Last updated: 19/12/2025, 19:20:53
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        vector<vector<int>>g(n);
        for(auto &e:swaps) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        vector<int>vis(n,0);
        long long ans = 0;
        for(int i=0;i<n;i++) if(!vis[i]){
            vector<int>ind,vals;
            stack<int>st; st.push(i); vis[i]=1;
            while(!st.empty()){
                int u = st.top(); st.pop();
                ind.push_back(u);
                vals.push_back(nums[u]);
                for(int v:g[u]) if(!vis[v]) vis[v]=1, st.push(v);
            }
            vector<int>ei,oi;
            for(auto id:ind) (id%2==0?ei:oi).push_back(id);
            sort(vals.rbegin(),vals.rend());
            int ein=0,oin=vals.size()-oi.size();
            for(auto id:ei) nums[id]=vals[ein++];
            for(auto id:oi) nums[id]=vals[oin++];
            for(int j:ind) ans+=(j%2==0?nums[j]:-nums[j]);
        }
        return ans;
    }
};