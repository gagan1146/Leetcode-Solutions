// Last updated: 19/12/2025, 19:22:58
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 return a[1] > b[1];
             });
        priority_queue<int> remain;
        priority_queue<int,vector<int>,greater<int>>chosen;
        int count =0;
        for(int i=0,k=0;i<nums.size();i++){
            while(!chosen.empty() && chosen.top()<i){
                chosen.pop();
            }
            while(k<queries.size() && queries[k][0]<=i){
                remain.push(queries[k++][1]);
            }
            while(chosen.size()<nums[i] && !remain.empty() && remain.top()>=i){
                chosen.push(remain.top());
                remain.pop();
                count++;
            }
            if(chosen.size()<nums[i]) return -1;
        }
        return queries.size()-count;
    }
};