class Solution {
public:
    
    void combinationSumUtil(vector<int> nums,vector<int> temp,vector<vector<int>> &s,int i,int n,int target)
    {
        if (target==0)
        {
            s.push_back(temp);
            return ;
        }
        else if (target>0)
        {
            for (int j=i; j<n; j++)
            {
                // if (j==i || nums[j]!=nums[j-1])
                // {
                    temp.push_back(nums[j]);
                    combinationSumUtil(nums,temp,s,j,n,target-nums[j]);
                    temp.pop_back();
                // }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        combinationSumUtil(candidates,temp,ans,0,n,target);
        return ans;
    }
};
