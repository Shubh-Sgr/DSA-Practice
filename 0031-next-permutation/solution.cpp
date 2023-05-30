class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int piv=n;

        for (int i=n-1; i>0; i--){
            if (nums[i]>nums[i-1]){
                piv=i-1;
                break;
            }
        }

        for (int i=n-1; i>piv; i--){
            if (nums[piv]<nums[i]){
                int temp=nums[piv];
                nums[piv] = nums[i];
                nums[i]=temp;
                sort(nums.begin()+piv+1,nums.end());
                break;
            }
        }
        if (piv==n){
            sort(nums.begin(),nums.end());
        }   
    } 
};
