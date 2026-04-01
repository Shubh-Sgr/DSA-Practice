class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int currLen = 0;
        int currSum=0;
        int n = nums.size();
        int l=0;

        for (int i=0; i<n; i++){
            currSum+=nums[i];

            while (currSum>=target){
                if (i-l+1<ans){
                    ans = i-l+1;
                }
                currSum-=nums[l];
                l++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
