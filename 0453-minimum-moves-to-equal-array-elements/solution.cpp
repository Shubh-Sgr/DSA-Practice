class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minEle = INT_MAX;
        int res = 0;
        for (int i=0; i<n; i++){
            minEle = min(minEle, nums[i]);
        }
        for (int i=0; i<n; i++){
            res+=(nums[i]-minEle);
        }
        return res;
    }
};
