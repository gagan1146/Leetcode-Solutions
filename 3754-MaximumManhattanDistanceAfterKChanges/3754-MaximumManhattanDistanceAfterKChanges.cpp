// Last updated: 19/12/2025, 19:22:24
class Solution {
public:
    int maxi = 0;
    // void f(int ind, string& s, int k, int n, int north, int south, int west,
    //        int east) {
    //     int y = abs(north - south) + abs(east - west);
    //     maxi = max(maxi, y);
    //     if (ind == n) {
    //         return;
    //     }
    //     if (k > 0) {
    //         f(ind + 1, s, k - 1, n, north + 1, south, west, east);
    //         f(ind + 1, s, k - 1, n, north, south + 1, west, east);
    //         f(ind + 1, s, k - 1, n, north, south, west + 1, east);
    //         f(ind + 1, s, k - 1, n, north, south, west, east + 1);
    //     }
    //     if (s[ind] == 'N') {
    //         f(ind + 1, s, k, n, north + 1, south, west, east);
    //     }
    //     else if (s[ind] == 'S') {
    //         f(ind + 1, s, k, n, north, south + 1, west, east);
    //     }
    //     else if (s[ind] == 'W') {
    //         f(ind + 1, s, k, n, north, south, west + 1, east);
    //     }
    //     else if (s[ind] == 'E') {
    //         f(ind + 1, s, k, n, north, south, west, east + 1);
    //     }
    // }
    int maxDistance(string s, int k) {
        int n = s.length();
        // f(0, s, k, n, 0, 0, 0, 0);
        int i=0,north=0,east=0,south=0,west=0;
        while(i<n){
            if(s[i]=='N'){
                north++;
            }
            else if(s[i]=='S'){
                south++;
            }
            else if(s[i]=='E'){
                east++;
            }
            else if(s[i]=='W'){
                west++;
            }
            int y = abs(west-east) + abs(north-south);
            int dis = y + min(2*k, i+1-y);
            maxi=max(maxi,dis);
            i++;
        }
        return maxi;
    }
};