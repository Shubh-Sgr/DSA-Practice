class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max=nums[0];
        int n= nums.size();
        if (n==1)
        {
            return true;
        }
        
        for (int i=0; i<=max; i++)
        {
            max=max<i+nums[i]?i+nums[i]:max;
            if (max>=n-1)
            {
                return true;
            }
        }
        
        return false;
    }
};
