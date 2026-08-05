class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int prev,curr;
        prev = nums[0] == 0 ? 1 : 0;
        if (n==1){
            return nums[0] == 0 ?1:0;
        }
        for (int i=1; i<n; i++){
            if (nums[i]==nums[i-1]){
                curr = prev;
            }else{
                curr = prev+1;
            }
            prev = curr;
        }
        return curr;
    }
};
