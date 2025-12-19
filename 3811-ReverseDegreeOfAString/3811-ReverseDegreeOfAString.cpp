// Last updated: 19/12/2025, 19:21:59
class Solution {
public:
    int reverseDegree(string s) {
        int c=0;
        for(int i=0;i<s.length();i++){
            c+=((26-(s[i]-'a'))*(i+1));
        }
        return c;
    }
};