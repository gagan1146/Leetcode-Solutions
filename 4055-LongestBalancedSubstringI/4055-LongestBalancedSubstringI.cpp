// Last updated: 19/12/2025, 19:20:28
class Solution {
public:
    int longestBalanced(string s) {
        int maxi = 0, n = s.length();
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[(s[j]-'a')]++;
                int x = 0;
                bool flag = true;
                for(int k=0;k<26;k++){
                    if(freq[k]>0 && x>0 && freq[k]!=x){
                        flag = false;
                        break;
                    }
                    if(freq[k]>0) x = freq[k];
                }
                if(flag) maxi = max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};