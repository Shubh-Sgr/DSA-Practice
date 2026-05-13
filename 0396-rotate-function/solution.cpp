class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int currVal = 0;
        int totalSum = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            currVal += i*nums[i];
            totalSum+=nums[i];
        }
        int maxSum = currVal;
        int currSum;
        for (int i=0; i<n-1; i++){
            currSum = totalSum - nums[n-i-1];
            currVal = currVal + currSum - nums[n-i-1]*(n-1);
            maxSum = max(maxSum, currVal);
        }
        return maxSum;
    }
};
