// Last updated: 19/12/2025, 19:23:07
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int a=0,b=0;
        if(events.size()==-1) return -1;
        a=events[0][0];
        b=events[0][1];
        for(int i=1;i<events.size();i++){
            if((events[i][1]-events[i-1][1])>b){
                a=events[i][0];
                b=events[i][1]-events[i-1][1];
            }
            else if((events[i][1]-events[i-1][1])==b){
                a = min(a,events[i][0]);
            }
        }
        return a;
    }
};