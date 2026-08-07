class Solution {
public:
    int minimumDeletions(string s) {
        int len = s.size();
        int dp[len+1] ;
        int bCount=0;
        dp[0] = 0;
        for (int i=0; i<len; i++){
            if (s[i]=='a'){
                dp[i+1] = min(dp[i]+1,bCount);
            }else{
                dp[i+1] = dp[i];
                bCount++;
            }
        }
        return dp[len];
    }
};
