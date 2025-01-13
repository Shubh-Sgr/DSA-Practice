class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();

        for (int i=0; i<n ; i++){
            int ind = abs(nums[i]);
            if (nums[ind]<0){
                ans = ind;
                break;
            }
            nums[ind] = -nums[ind];
        }
        return ans;
    }
};
