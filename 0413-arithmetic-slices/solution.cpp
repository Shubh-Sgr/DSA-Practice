class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if (n<=2)
        {
            return 0;
        }
        int diff=nums[1]-nums[0];
        int count=2,ans=0;
        for (int i=2; i<n; i++)
        {
            if (nums[i]-nums[i-1]!=diff)
            {
                if (count>=3)
                {
                    ans+=((count-2)*(count-1))/2;
                }
                count=2;
                diff=nums[i]-nums[i-1];
            }
            else
            {
                count++;
            }
        }
        if (count!=0 && count>=3)
        {
             ans+=((count-2)*(count-1))/2;
        }
        return ans;
    }
};
