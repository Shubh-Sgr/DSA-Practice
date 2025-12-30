class Solution {
public:
    static void subSumUtilDup(vector<int> nums, int ind, vector<int> temp, vector<vector<int>> &ans, int n){
            ans.push_back(temp);

        for (int i=ind; i<n; i++){
            if (i==ind || nums[i]!= nums[i-1]){
                temp.push_back(nums[i]);
                subSumUtilDup(nums,i+1,temp,ans,n);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        subSumUtilDup(nums,0,temp,ans,n);
        return ans;
    }
};
