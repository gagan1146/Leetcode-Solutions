// Last updated: 19/12/2025, 19:23:10
class Solution {
public:
    int smallestNumber(int n, int t) {
        int flag=1;
        while(flag!=0){
            int x=n%10,n1=n/10;
            while(n1>0){
                x=x*(n1%10);
                n1=n1/10;
            }
            if(x%t==0){
                return n;
            }
            n++;
        }
        return n;
    }
};