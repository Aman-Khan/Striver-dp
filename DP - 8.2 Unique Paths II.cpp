//https://leetcode.com/problems/unique-paths-ii

    int reachAtTheEnd(int x, int y, vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp){
        if(x>=m || y>=n) return 0;
        if(obstacleGrid[x][y]==1){
            return dp[x][y]=0;
        }
        if(x==m-1 && y==n-1){
            return dp[x][y]=1;
        }
        if(dp[x][y]!=-1) return dp[x][y];

        int right = reachAtTheEnd(x, y+1, obstacleGrid, m, n, dp);
        int down = reachAtTheEnd(x+1, y, obstacleGrid, m, n, dp);
        return dp[x][y]=right+down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        reachAtTheEnd(0, 0, obstacleGrid, m, n, dp);
        return dp[0][0];
    }
