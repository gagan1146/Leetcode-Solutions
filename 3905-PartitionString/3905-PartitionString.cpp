// Last updated: 19/12/2025, 19:21:20
class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string>st;
        vector<string>ans;
        string c="";
        for( auto i: s){
            c+=i;
            if(st.find(c)==st.end()){
                ans.push_back(c);
                st.insert(c);
                c="";
            }
        }
        return ans;
    }
};