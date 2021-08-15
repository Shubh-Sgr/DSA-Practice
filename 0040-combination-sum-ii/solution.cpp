class Solution {
public:
    void combinationSum2Util(vector<int> nums,vector<vector<int>> &ans,vector<int> temp,int i,int n ,int target)
    {
        if (target==0)
        {
            ans.push_back(temp);
        }
        else if (target>0)
        {
            for (int j=i; j<n; j++)
            {
                if (j==i || nums[j]!=nums[j-1])
                {
                    temp.push_back(nums[j]);
                    combinationSum2Util(nums,ans,temp,j+1,n,target-nums[j]);
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        combinationSum2Util(candidates,ans,temp,0,n,target);
        return ans;
    }
};
