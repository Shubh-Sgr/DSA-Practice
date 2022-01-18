class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n];
        int maxM=arr[0];
        
        for (int i=0; i<k; i++)
        {
            maxM=max(maxM,arr[i]);
            dp[i]=maxM*(i+1);
        }
        
        for (int i=k; i<n; i++)
        {
            dp[i] = arr[i] + dp[i-1];
            maxM=arr[i];
            
            for (int j=i-1; j>i-k; j--)
            {
                maxM=max(arr[j],maxM);
                dp[i]=max(dp[i],dp[j-1]+(i-j+1)*maxM);
            }
        }
        return dp[n-1];
    }
};
