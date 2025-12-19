// Last updated: 19/12/2025, 19:23:59
class Solution {
public:
    string compressedString(string word) {
        string s1="";
        if(word.length()==1){
            s1+=to_string(1);
            s1+=word[0];
            return s1;
        }
        int i=0,c=1;
        while(i<word.length()-1){
            if(word[i]==word[i+1]){
                c++;
            }
            else{
                if(c>0){
                    s1+=to_string(c);
                    s1+=word[i];
                }
                c=1;
            }
            if(c==9){
                s1+=to_string(c);
                c=0;
                s1+=word[i];
            }
            i++;
        }
        if(word[i]!=word[i-1]){
            s1+=to_string(1);
            s1+=word[i];
        }
        else if(word[i]==word[i-1] && c!=0){
            s1+=to_string(c);
            s1+=word[i];
        }
        return s1;
    }
};