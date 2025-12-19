// Last updated: 19/12/2025, 19:19:49
class Solution {
public:
    string Trim(string s){
        while(s.length()>0){
            if(s[0]=='0') s = s.substr(1,s.length()-1);
            else break;
        }
        if(s.length()==0) return "0";
        return s;
    }
    string Binary(int n){
        string ans = "";
        while(n>0){
            ans += (n%2+'0');
            n/=2;
        }
        return ans;
    }
    int Reflection(int n){
        string s = Binary(n);
        s = Trim(s);
        return stoi(s, nullptr, 2);
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>>v;
        for(auto it: nums){
            int x = Reflection(it);
            v.push_back({x,it});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<nums.size();i++){
            nums[i] = v[i].second;
        }
        return nums;
    }
};