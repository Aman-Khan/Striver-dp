//https://leetcode.com/problems/unique-paths

    int roboMoves(int x, int y, int m, int n, vector<vector<int>>& dp){
        if(x>m-1 || y>n-1) return 0;
        if(x==m-1 && y==n-1){
            return dp[x][y]=1;
        }
        if(dp[x][y]!=-1) return dp[x][y];

        int right = roboMoves(x+1, y, m, n, dp);
        int down = roboMoves(x, y+1, m, n, dp);
        return dp[x][y]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        roboMoves(0, 0, m, n, dp);
        return dp[0][0];
    }                
