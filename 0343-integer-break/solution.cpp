class Solution {
public:
    int integerBreak(int n) {
        // dp[i] will store the maximum product for number i
        std::vector<int> dp(n + 1, 0);
        
        // Base case: for n=1, the max product is technically 1
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            // We only need to check up to i/2 because of symmetry
            for (int j = 1; j <= i / 2; ++j) {
                /* For each split j, we compare:
                   1. j * (i - j) -> Breaking i into exactly two pieces
                   2. j * dp[i - j] -> Breaking i into j and then the best split of (i - j)
                */
                int currentMax = std::max(j * (i - j), j * dp[i - j]);
                dp[i] = std::max(dp[i], currentMax);
            }
        }
        
        return dp[n];
    }
};
