// Last updated: 19/12/2025, 19:22:28
class Solution {
public:
    long long MAXI = 1000000000;
    map<long long, long long>mp;
    void f(){
        long long low = 4,k=1;
        mp[0]=0;
        while(low<=MAXI){
            mp[low-1]=k;
            k++;
            low=low*4;
        }
    }
    long long calc(long long val){
        long long low =0, prev = -1, count = 0;
        for(auto it: mp){
            if(it.first<val){
                if(prev!=-1){
                    count = count + (it.second*(it.first-prev));
                    prev=it.first;
                }
                else{
                    prev=it.first;
                    count = 0;
                }
            }
            else break;
        }
        if(prev!=-1) count = count + (val-prev)*(mp[prev]+1);
        else count = val;
        return count;
    }
    long long minOperations(vector<vector<int>>& queries) {
        f();
        long long ans = 0;
        for(auto it: queries){
            long long a = it[0], b = it[1];
            long long low = calc(a-1), high = calc(b);
            ans = ans + ceil(( high - low )/2.0);
        }
        return ans;
    }
};