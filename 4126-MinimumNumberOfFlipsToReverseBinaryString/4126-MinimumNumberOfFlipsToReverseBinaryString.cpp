// Last updated: 19/12/2025, 19:19:55
class Solution {
public:
    int minimumFlips(int n) {
        string x = "";
        while(n>0){
            if(n%2==0) x+='0';
            else x+= '1';
            n/=2;
        }
        string x1 = x;
        reverse(x1.begin(),x1.end());
        int ans = 0;
        for(int i=0;i<x.length();i++){
            if(x[i]!=x1[i]) ans++;
        }
        return ans;
    }
};