class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ump;
        vector<int> ans;

        int n = nums.size();
        for (int i=0; i<n; i++){
            if (ump.find(target-nums[i]) == ump.end()){
                ump[nums[i]]=i;
            }
            else{
                ans.push_back(ump[(target-nums[i])]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
