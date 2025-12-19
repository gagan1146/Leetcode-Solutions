// Last updated: 19/12/2025, 19:22:33
class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long n= instructions.size(),val=0,maxi=0;
        vector<long long>vis(n, -1) ;
        while(true){
        if(val>=n || val<0) return maxi;
        if(vis[val]!=-1) return maxi;
        vis[val]=1;
        if(instructions[val]=="add"){
        maxi+=(values[val]) ;
        val++;
        }
        else if(instructions[val]=="jump"){
        val+=values[val];
        }
        }
        return maxi;
    }
};