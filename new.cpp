link : https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

TC

int maxMerit(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
    if(day==points.size()-1){
        int maxi = 0;
        for(int task=0; task<3; task++){
            if(last!=task){
                maxi = max(maxi, dp[day][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last]!=-1) return dp[day][last];

    int ans = 0;
    for(int task=0; task<3; task++){
        if(task!=last){
            int merit = points[day][task]+maxMerit(day+1, task, points, dp);
            ans = max(ans, merit);
        }
    }
    return dp[day][last]=ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(3,-1));
    for(int i=0; i<3; i++){
        dp[n-1][i]=points[n-1][i];
    }
    int ans = 0;
    for(int i=0; i<3; i++){
        int merit = maxMerit(0, i, points, dp);
        ans = max(ans, merit);
    }
    return ans;
}
