class Solution {
public:
    void calcSubsets(vector<int> nums,set<vector<int>> &s,int n,vector<int> temp)
    {
        if (n>0)
        {
            vector<int> exc=temp;
            vector<int> inc=temp;
            inc.push_back(nums[n-1]);
            sort(inc.begin(),inc.end());
            sort(exc.begin(),exc.end());
            if (n==1)
            {
                s.insert(inc);
                s.insert(exc);
                return;
            }
            calcSubsets(nums,s,n-1,inc);
            calcSubsets(nums,s,n-1,exc);
        }
    }
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> temp;
        int n=nums.size();
        calcSubsets(nums,s,n,temp);
        vector<vector<int>> v;
        for (set<vector<int>>::iterator it=s.begin(); it!=s.end(); it++)
        {
            v.push_back(*it);
        }
        return v;
    }
};
