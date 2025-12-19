// Last updated: 19/12/2025, 19:23:18
class Solution {
public:
    int possibleStringCount(string word) {
        int i=0;
        int n=word.length();
        int c=0;
        while(i<n-1){
            if(word[i]==word[i+1]) c++;
            i++;
        }
        return c+1;
    }
};