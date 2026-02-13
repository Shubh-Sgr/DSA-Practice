class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = nums[0];
        int i=0;
        if (n==1){
            return true;
        }

        while(i<=maxJump){
            maxJump = max(maxJump, i+nums[i++]);
            if (maxJump >= n-1){
                return true;
            }
        }
        return false;
    }
};
