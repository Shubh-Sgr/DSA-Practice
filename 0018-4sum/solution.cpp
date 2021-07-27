class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
        if (nums.size()<=3)
        {
            return ans;
        }
       for (int i=0; i<=nums.size()-4; i++)
       {
           if (i!=0 && nums[i]==nums[i-1])
           {
               continue;
           }
           for (int j=i+1; j<=nums.size()-3; j++)
           {
               if (j!=i+1 && nums[j]==nums[j-1])
               {
                   continue;
               }
               long long sum=nums[i]+nums[j];
               int l=j+1;
               int r=nums.size()-1;
               while (l<r)
               {
                   if (sum+nums[l]+nums[r]==target)
                   {
                       vector<int> v;
                       v.push_back(nums[i]);
                       v.push_back(nums[j]);
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
                   else if (sum+nums[l]+nums[r]<target)
                   {
                       l++;
                   }
                   else
                   {
                       r--;
                   }
               }
           }
       }
       return ans;
    }
};
