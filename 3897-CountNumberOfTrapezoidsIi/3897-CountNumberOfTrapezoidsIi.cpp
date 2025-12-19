// Last updated: 19/12/2025, 19:21:24
class Solution {
public:
    pair<int,int> getSlope(const vector<int>& p1, const vector<int>& p2) {
        int dx = p2[0] - p1[0];
        int dy = p2[1] - p1[1];
        if(dx == 0) return {1, 0};
        if(dy == 0) return {0, 1};
        int g = __gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
        if(dx < 0) {
            dx = -dx;
            dy = -dy;
        }
        return {dy, dx};
    }
    
    long long getIntercept(const vector<int>& p, pair<int,int> slope) {
        int dy = slope.first;
        int dx = slope.second;
        return (long long)p[1] * dx - (long long)p[0] * dy;
    }
    
    int countTrapezoids(vector<vector<int>>& points) {
        map<pair<int,int>, map<long long, int>> mp;
        

        map<long long, map<pair<int,int>, map<long long, int>>> mpLength;
        
        for(int i = 0; i < (int)points.size(); i++) {
            for(int j = i + 1; j < (int)points.size(); j++) {
                pair<int,int> slope = getSlope(points[i], points[j]);
                long long intercept = getIntercept(points[i], slope);
                long long length = (long long)(points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + 
                                  (long long)(points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                mp[slope][intercept]++;
                mpLength[length][slope][intercept]++;
            }
        }
        
        long long finalAns = 0;
        for(auto &it : mp) {
            vector<int> v;
            long long tot = 0;
            for(auto &sit : it.second) {
                v.push_back(sit.second);
                tot += sit.second;
            }
            long long ans = 0, sub = 0;
            for(size_t i = 0; i < v.size(); i++) {
                sub += v[i];
                ans += 1LL * v[i] * (tot - sub);
            }
            finalAns += ans;
        }
        
        long long squares = 0;
        for(auto &it : mpLength) {
            for(auto &sit : it.second) {
                vector<int> v;
                long long tot = 0;
                for(auto &tit : sit.second) {
                    v.push_back(tit.second);
                    tot += tit.second;
                }
                long long ans = 0, sub = 0;
                for(size_t i = 0; i < v.size(); i++) {
                    sub += v[i];
                    ans += 1LL * v[i] * (tot - sub);
                }
                squares += ans;
            }
        }
        
        return (int)(finalAns - squares/2);
    }
};