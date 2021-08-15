class Solution {
public:
    void calcSubsets(vector<int> nums,vector<vector<int>> &s,int i,int n,vector<int> temp)
    {
        s.push_back(temp);
        for (int j=i; j<n; j++)
        {
            if (j == i || nums[j] != nums[j - 1]) { 
				temp.push_back(nums[j]);
				calcSubsets(nums,s,j+1,n,temp);
				temp.pop_back();
			}
        }
    }
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        int n=nums.size();
        calcSubsets(nums,v,0,n,temp);
        return v;
    }
};
