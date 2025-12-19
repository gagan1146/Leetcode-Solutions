// Last updated: 19/12/2025, 19:24:12
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxi = -1e9, n = energy.size();
        for(int i=0;i<n;i++){
            if(i>=k) if(energy[i-k]>=0) energy[i]+=energy[i-k];
            if(i>=n-k) maxi=max(maxi,energy[i]);
        }
        return maxi;
    }
};