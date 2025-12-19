// Last updated: 19/12/2025, 19:20:42
class Solution {
public:
    bool f1(int i,string&h,vector<int>c,int k){
        if(i==k) return true;
        for(int j=0;j<26;j++) if(c[j]){
            h[i]='a'+j;
            c[j]--;
            if(f1(i+1,h,c,k)) return true;
            c[j]++;
        }
        return false;
    }
    bool f2(int i,string &h,vector<int>c,int k,string&target,char m,vector<int>v){
        if(i==k){
            string p = h;
            if(m)p+=m;
            string r = h;
            reverse(r.begin(),r.end());
            p+=r;
            return p>target;
        }
        char x = target[i];
        if(c[x-'a']){
            h[i]=x;
            c[x-'a']--;
            if(f2(i+1,h,c,k,target,m,v)) return true;
            c[x-'a']++;
        }
        for(int j=x-'a'+1;j<26;j++) if(c[j]){
            h[i]='a'+j;
            c[j]--;
            string hc=h;
            vector<int>cc=c;
            if(f1(i+1,hc,cc,k)){h=hc;return true;}
            c[j]++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int>v(26);
        for(char x:s) v[(x-'a')]++;
        char m=0;
        int o=0,k=n/2;
        vector<int>v1(26);
        for(int i=0;i<26;i++){
            if(v[i]%2)o++,m='a'+i;
            v1[i]=v[i]/2;
        }
        if((n%2==0 && o>0) || (n%2&&o!=1)) return "";
        string h(k,' ');
        if(f2(0,h,v1,k,target,m,v)){
            string p = h;
            if(m)p+=m;
            string r = h;
            reverse(r.begin(),r.end());
            p+=r;
            return p;
        }
        return "";
    }
};