class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n=nums.size();
       int max=nums[0];
        
       for (int i=0; i<=max; i++)
       {
           max=nums[i]+i>max?nums[i]+i:max;
           if (max>=n-1)
           {
               return true;
           }
       } 
        return false;
    }
};
