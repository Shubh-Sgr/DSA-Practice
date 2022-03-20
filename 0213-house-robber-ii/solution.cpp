class Solution {
public:
    
    int Util(vector<int> nums, int l, int r)
    {
        int pre=0,curr=0,temp=0;
        for (int i=l; i<=r; i++)
        {
            temp=max(pre+nums[i],curr);
            pre=curr;
            curr=temp;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1)
        {
            return nums[0];
        }
        return max(Util(nums,0,n-2),Util(nums,1,n-1));    
    }
};
