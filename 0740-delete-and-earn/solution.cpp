class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10002;
        vector<int> v(n,0);
        for (int i=0; i<nums.size(); i++){
            v[nums[i]]+=nums[i];
        }

        for (int i=2; i<n; i++){
            v[i] = max(v[i-2]+v[i],v[i-1]);
        }
        return v[n-1];
    }
};
