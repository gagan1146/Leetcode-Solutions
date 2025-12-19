// Last updated: 19/12/2025, 19:20:26
class Solution {
public:
    int f(int i){
        string x = to_string(i);
        int c = 0;
        for(int i=1;i<x.length()-1;i++){
            if((x[i]>x[i-1] && (x[i]>x[i+1]))||((x[i]<x[i-1]) && (x[i]<x[i+1]))) c++;
        }
        return c;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=max(num1,100);i<=num2;i++){
            int c = f(i);
            ans += c;
        }
        return ans;
    }
};