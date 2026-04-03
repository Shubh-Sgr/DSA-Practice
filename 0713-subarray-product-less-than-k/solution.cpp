class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int prod = 1;
        int start = 0;
        for (int i=0; i<nums.size(); i++){
            prod = prod*nums[i];
            while (prod>=k && start<nums.size()){
                prod = prod/nums[start];
                start+=1;
            }
            if (prod==0){
                prod = 1;
            }
            if (prod<k){
                ans+=((i-start)+1);
            }
        }
        return ans;
    }
};
