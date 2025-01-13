class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int l = 0;
        int r = n - 1;

        while (i <= r) {
            if (nums[i] == 0) {
                int temp = nums[i];
                nums[i] = nums[l];
                nums[l] = temp;
                l++;
                i++;
            } else if (nums[i] == 2) {
                int temp = nums[i];
                nums[i] = nums[r];
                nums[r] = temp;
                r--;
            } else {
                i++;
            }
        }
    }
};
