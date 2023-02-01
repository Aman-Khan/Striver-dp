    int minPath(int x, int y, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(x>=triangle.size()) return 1e8;
        if(y>=triangle[x].size()) return 1e8;
        if(x==triangle.size()-1) {
            return dp[x][y]=triangle[x][y];
        }
        if(dp[x][y]!=-1) return dp[x][y];

        int btm = minPath(x+1, y, triangle, dp);
        int btmRgt = minPath(x+1, y+1, triangle, dp);

        return dp[x][y]=min(btm, btmRgt)+triangle[x][y];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return minPath(0, 0, triangle, dp);
    }
