// Last updated: 19/12/2025, 19:21:00
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        map<int,int>mp1,mp2;
        int mini = 1e9;
        for(int i=0;i<landStartTime.size();i++){
            for(int j=0;j<waterStartTime.size();j++){
                int x = waterStartTime[j]+waterDuration[j];
                if(x<landStartTime[i]){
                    mini = min(mini,landStartTime[i]+landDuration[i]);
                }
                else{
                    mini=min(mini,x+landDuration[i]);
                }
                x = landStartTime[i]+landDuration[i];
                if(x<waterStartTime[j]){
                    mini = min(mini,waterStartTime[j]+waterDuration[j]);
                }
                else{
                    mini=min(mini,x+waterDuration[j]);
                }
            }
        }
        return mini;
    }
};