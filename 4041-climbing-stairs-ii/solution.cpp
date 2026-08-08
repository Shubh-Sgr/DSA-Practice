class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int dp[n+1];
        if (n==0){
            return 0;
        }
        dp[0] = 0;
        dp[1] = costs[0] + 1;
        if (n==1){
            return dp[1];
        }
        dp[2] = min(costs[1] + 4, dp[1]+ costs[1]+1);
        if (n==2){
            return dp[2];
        }
        for (int i=2; i<n; i++){
            dp[i+1] = min(dp[i-2] + 9, min(dp[i-1] + 4, dp[i]+1))+costs[i];
        }
        return dp[n];
    }
};
