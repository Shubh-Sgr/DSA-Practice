class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int,int> ump;
        ump[0] = 1;
        int rem;
        int sum = 0 ;
        int ans = 0;

        for (int i=0; i<len; i++){
            sum+=nums[i];
            rem = sum%k;
            if (rem<0){
                rem+=k;
            }
            ans+=ump[rem]++;
        }

        return ans;
    }
};
