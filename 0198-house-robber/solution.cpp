class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();

       if (n==1){
         return nums[0];
       } 
       else if (n==2){
            return max(nums[0],nums[1]);
       }
       int prev1 = nums[0];
       int curr1 = max(nums[0],nums[1]);
       for (int i=2; i<n; i++){
          int temp = curr1;
          curr1 = max(curr1, prev1+nums[i]);
          prev1 = temp;
       }

       return curr1;
    }
};
