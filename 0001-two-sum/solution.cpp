class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ump;
        vector<int> v;
        
        for (int i=0; i<nums.size(); i++)
        {
            if (ump.find(target-nums[i])!=ump.end())
            {
                v.push_back(ump[target-nums[i]]);
                v.push_back(i);
                break;
            }
            else
            {
                ump[nums[i]]=i;
            }
        }
        return v;
    }
};
