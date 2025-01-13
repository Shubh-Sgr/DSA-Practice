class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        for (int i=n-1; i>0; i--){
            if (nums[i] > nums[i-1]){
                pivot = i-1;
                break;
            }
        }

        if (pivot == -1){
            sort(nums.begin(),nums.end());
            return;
        }

        for (int i=n-1; i>=0; i--){
            if (nums[pivot] < nums[i]){
                int temp = nums[i];
                nums[i] = nums[pivot];
                nums[pivot] = temp;
                sort(nums.begin()+pivot+1,nums.end());
                break;
            }
        }
    }
};
