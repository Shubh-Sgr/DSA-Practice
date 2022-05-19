class Solution {
public:
    int climbStairs(int n) {
        if (n<=0)
            return 0;
        if (n==1 || n==2)
            return n;
        
        int onestep=1;
        int twostep=2;
        int curr;
        
        
        for (int i=3; i<=n; i++)
        {
            curr=onestep+twostep;
            onestep=twostep;
            twostep=curr;
        }
        
        return curr;
    }
};
