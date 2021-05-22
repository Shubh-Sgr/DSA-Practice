class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int T_sum=0;
        int n=nums.size();
        for (int i=0; i<n; i++){
            T_sum+=nums[i];
        }
        // cout<<T_sum<<"ooo";
        if (target>T_sum || (target+T_sum)%2!=0){
            return 0;
        }
        int F_sum=(target+T_sum)/2;
         // cout<<F_sum<<"loo";
        int dp[n+1][F_sum+1];
        for (int i=0; i<=F_sum; i++){
            dp[0][i]=0;
        }
        for (int i=0; i<=n; i++){
            dp[i][0]=1;
        }
        for (int i=1; i<=n; i++){
            for (int j=0; j<=F_sum; j++){
                if (j<nums[i-1]){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][F_sum];
    }
};
