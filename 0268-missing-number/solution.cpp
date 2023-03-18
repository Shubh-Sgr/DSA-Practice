class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int orig = 0;
        int n = nums.size()+1;
        for (int i=0; i<n; i++){
            orig = orig ^ i;
        }

        int curr = 0;
        for (int i=0; i<n-1; i++){
            curr = curr ^ nums[i];
        }
        return curr^orig;
    }
};
