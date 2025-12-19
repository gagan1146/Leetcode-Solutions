// Last updated: 19/12/2025, 19:21:11
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
    using ll = long long;
public:
    int popcount(long long n){
        if (n == 1) return 0; 
        int c = 0;
        while(n != 1){
            n = __builtin_popcountll(n);
            c++;
        }
        return c;
    }
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        vector<ordered_set<int>> v(6);
        for(int i = 0; i < (int)nums.size(); i++){
            int ans = popcount(nums[i]);
            v[ans].insert(i);
        }
        vector<int> res;
        for(auto& i: queries){
            if(i[0] == 1){
                int l = i[1], r = i[2], k = i[3];
                res.push_back(v[k].order_of_key(r + 1) - v[k].order_of_key(l));
            }
            else{
                int x = i[1];
                ll val = i[2];
                int k1 = popcount(nums[x]);
                v[k1].erase(x);
                nums[x] = val;
                int k2 = popcount(nums[x]);
                v[k2].insert(x);
            }
        }
        return res;
    }
};