class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // unordered_map<vector<int>,int> ump;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l,r,ele;
        for (int i=0; i<n-2; i++)
        {
            if (i==0 || (i>0 && nums[i]!=nums[i-1])){
                ele=-nums[i];
                l=i+1;
                r=n-1;
                while (l<r)
                {
                    if (nums[l]+nums[r]<ele)
                    {
                        l++;
                    }
                    else if (nums[l]+nums[r]>ele)
                    {
                        r--;
                    }
                    else
                    {
                        vector<int> v;

                        v.push_back(nums[i]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        ans.push_back(v);
                        l++;
                        while (l<r && nums[l]==nums[l-1])
                        {
                            l++;
                        }
                        r--;
                        while (l<r && nums[r]==nums[r+1])
                        {
                            r--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
