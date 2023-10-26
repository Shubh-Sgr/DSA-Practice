class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int,int> ump;
        int sum=0;
        int ans=0;
        ump[sum] = 1;
        for (int i=0; i<size; i++){
          sum+=nums[i];
          if (ump.find(sum-k)!=ump.end()){
            ans+=ump[sum-k];
          }
          ump[sum] += 1;
        }
        return ans;
    }
};
