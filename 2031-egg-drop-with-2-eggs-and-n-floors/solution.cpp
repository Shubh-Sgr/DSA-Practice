class Solution {
public:
     int dp[3][1001];
    int Util(int floors,int eggs)
    {
        if (eggs == 1 || floors<=2)
        {
            return floors;
        }
        if (dp[eggs][floors]>0)
        {
            return dp[eggs][floors];
        }
        int minMove=floors;
        
        for (int i=1; i<floors; i++)
        {
            int broken=dp[eggs-1][i-1];
            if (dp[eggs-1][i-1]==0)
            {
                broken = Util(i-1,eggs-1);
            }
            int unbroken = dp[eggs][floors-i];
            if ( dp[eggs][floors-i] == 0)
            {
                unbroken = Util(floors-i,eggs);
            }
            int move = 1+max(broken,unbroken);
            minMove = min(move,minMove);
        }
        dp[eggs][floors]=minMove;
        return minMove;
    }
    
    int twoEggDrop(int n) {
        memset(dp,0,sizeof(dp));
        return Util(n,2);
    }
};
