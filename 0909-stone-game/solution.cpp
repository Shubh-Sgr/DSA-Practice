class Solution {
public:
    int dp[501][501];
    
    int Util(int l, int r, vector<int>& piles)
    {
        if (l>r)
        {
            return 0;
        }
        if (dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        int leftChoosen = piles[l] + max(Util(l+2,r,piles),Util(l+1,r-1,piles));
        int rightChoosen = piles[r] + max(Util(l+1,r-1,piles),Util(l,r-2,piles));
        
        return dp[l][r]=max(leftChoosen,rightChoosen);
    }
    
    bool stoneGame(vector<int>& piles) {
        int l=0,r=piles.size()-1;
        memset(dp,-1,sizeof(dp));
        int alex=Util(l,r,piles);
        int total_sum=0;
        for (int i=0; i<=r; i++)
        {
            total_sum+=piles[i];
        }
        return alex>total_sum-alex;
    }
};
