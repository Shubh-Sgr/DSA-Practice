class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if (n==0)
        {
            return 0;
        }
        int curr_sum=nums[0];
        int max_sum=nums[0];
        
        for (int i=1; i<n; i++)
        {
            if (nums[i]+curr_sum<nums[i])
            {
                curr_sum=nums[i];
            }
            else
            {
                curr_sum+=nums[i];
            }
            if (curr_sum>max_sum)
            {
                max_sum=curr_sum;
            }
        }
        return max_sum;
    }
};
