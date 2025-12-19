// Last updated: 19/12/2025, 19:21:55
class Solution {
public:
    vector<vector<int>>dir={{0,-1},{-1,0},{0,1},{1,0}};
    int countIslands(vector<vector<int>>& grid, int k) {
        queue<pair<int,int>>q;
        int m = grid.size(), ans=0, n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==-1 && grid[i][j]!=0){
                    vis[i][j]=1;
                    long long sumi = 0;
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        sumi+=(grid[x][y]);
                        q.pop();
                        for(int k1=0;k1<4;k1++){
                            int a = dir[k1][0] + x;
                            int b = dir[k1][1] + y;
                            if(a>=0 && b>=0 && a<m && b<n && vis[a][b]==-1 && grid[a][b]!=0){
                                q.push({a,b});
                                vis[a][b]=1;
                            }
                        }
                    }
                    if(sumi%k==0) ans++;
                }
            }
        }
        return ans;
    }
};