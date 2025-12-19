// Last updated: 19/12/2025, 19:21:04
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size(), c = 0;
        for(int i=0;i<n;i++){
            int maxi = weight[i], j = i;
            while(j<n){
                if(weight[j]<maxi){
                    c++;
                    i=j;
                    break;
                }
                maxi=max(maxi,weight[j]);
                j++;
            }
            if(j>=n) break;
        }
        return c;
    }
};