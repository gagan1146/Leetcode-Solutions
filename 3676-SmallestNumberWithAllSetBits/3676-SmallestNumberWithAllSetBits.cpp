// Last updated: 19/12/2025, 19:22:49
class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        while((x-1)<n){
            x=x<<1;
        }
        return x-1;
    }
};