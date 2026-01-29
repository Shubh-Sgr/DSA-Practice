class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maxLength = 0;
        vector<int> zeroIndices;  // store indices of zeros
        
        for (int right = 0; right < nums.size(); right++) {
            // If current element is 0, store its index
            if (nums[right] == 0) {
                zeroIndices.push_back(right);
            }
            
            // If we have more than k zeros in window
            if (zeroIndices.size() > k) {
                // Move left to just after the first zero
                left = zeroIndices[0] + 1;
                // Remove the first zero from vector
                zeroIndices.erase(zeroIndices.begin());
            }
            
            // Update max length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
