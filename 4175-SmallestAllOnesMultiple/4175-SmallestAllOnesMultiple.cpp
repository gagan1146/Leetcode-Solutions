// Last updated: 29/12/2025, 21:48:10
class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0||k%5==0) return -1;
        int r = 0;
        for(int i=1;i<=k;i++){
            r=(r*10+1)%k;
            if(r==0) return i;
        }
        return -1;
    }
};