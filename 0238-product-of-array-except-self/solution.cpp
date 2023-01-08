class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int n = nums.size();
        int countZero = 0;

        for (int i=0; i<n; i++){
            if (nums[i]!=0){
                prod = prod*nums[i];
            }
            if (nums[i]==0){
                countZero++;
            }
        } 

        vector<int> ans;
        for (int i=0; i<n; i++){
            if (nums[i]==0 && countZero == 1){
                ans.push_back(prod);
            }
            else if (nums[i]==0 && countZero > 1){
                ans.push_back(0);
            }
            if (nums[i]!=0 && countZero>0){
                ans.push_back(0);
            }
            else if (nums[i]!=0 && countZero==0){
                ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }
};
