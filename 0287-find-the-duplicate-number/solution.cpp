class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n==0){
            return -1;
        }
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (fast!=slow){
            slow=nums[slow];
            fast =  nums[nums[fast]];
        }
        fast=0;
        while (fast!=slow){
            slow=nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
