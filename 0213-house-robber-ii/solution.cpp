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
       int temp;
       for (int i=2; i<n-1; i++){
        temp = curr1;
        curr1 = max(curr1, prev1+nums[i]);
        prev1 = temp;
       }

       int prev2 = nums[1];
       int curr2 = max(nums[1],nums[2]);
       for (int i=3; i<n; i++){
        temp = curr2;
        curr2 = max(curr2, prev2+nums[i]);
        prev2 = temp;
       }
       return max(curr1,curr2);
    }
};
