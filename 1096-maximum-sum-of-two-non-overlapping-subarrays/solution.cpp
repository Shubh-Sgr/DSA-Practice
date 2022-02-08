class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        for (int i=1; i<n; i++)
        {
            nums[i]+=nums[i-1];
        }
        
        int l=firstLen,m=secondLen;
        int lMax=nums[l-1];
        int rMax=nums[m-1];
        int ans=nums[l+m-1];
        
        for (int i=l+m; i<n; i++)
        {
            lMax=max(lMax,nums[i-m]-nums[i-l-m]);
            rMax=max(rMax,nums[i-l]-nums[i-l-m]);
            
            ans=max(ans,max(lMax+nums[i]-nums[i-m],rMax+nums[i]-nums[i-l]));
        }
        return ans;
    }
};
