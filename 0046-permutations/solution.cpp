class Solution {
public:
    
    void permuteUtil(vector<int> &nums,vector<vector<int>> &v,int n,int index)
    {
        if (index==n)
        {
            
            v.push_back(nums);
            return;
        }
        for (int i=index; i<n; i++)
        {
            int temp=nums[index];
            nums[index]=nums[i];
            nums[i]=temp;
            permuteUtil(nums,v,n,index+1);
            temp=nums[index];
            nums[index]=nums[i];
            nums[i]=temp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size();
        permuteUtil(nums,v,n,0);
        return v;
    }
};
