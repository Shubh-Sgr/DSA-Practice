class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        int rightEven=0,rightOdd=0,leftEven=0,leftOdd=0;
        
        for (int i=0; i<n; i++)
        {
            if (i%2==0)
            {
                rightEven+=nums[i];
            }
            else
            {
                rightOdd+=nums[i];
            }
        }
        
        int ans=0;
        for (int i=0; i<n; i++)
        {
            if (i%2==0)
            {
                rightEven-=nums[i];
            }
            else
            {
                rightOdd-=nums[i];
            }
            
            if (leftOdd+rightEven==leftEven+rightOdd)
            {
                ans++;
            }
            
            if (i%2==0)
            {
                leftEven+=nums[i];
            }
            else
            {
                leftOdd+=nums[i];
            }
        }
        
        return ans;
    }
};
