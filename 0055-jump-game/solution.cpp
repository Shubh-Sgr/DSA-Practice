class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max=nums[0];
        for (int i=0; i<=max; i++)
        {
            max=(nums[i]+i)>max?nums[i]+i:max;
            if (max>=nums.size()-1)
            {
                return true;
            }
        }
        return false;
    }
};
