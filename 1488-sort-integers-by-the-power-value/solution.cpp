class Solution {
public:
    int solve(int n)
    {
        if(n==1)
        return 0;

        if(dp.find(n)!=dp.end())
        return dp[n];

        if(n%2==0)
        return dp[n] = 1+solve(n/2);

        return dp[n] = 1+solve(3*n+1);
    }
        unordered_map<int,int> dp;

    int getKth(int lo, int hi, int k) {
        
        vector<pair<int,int>> ans;
        for(int i = lo;i<=hi;i++)
        ans.push_back({solve(i),i});
        
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};
