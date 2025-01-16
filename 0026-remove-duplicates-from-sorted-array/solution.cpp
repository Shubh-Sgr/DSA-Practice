class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int pivot = 1;

        int len = nums.size();
        if (len == 1){
            return 1;
        }
        int num = nums[0];

        for (int i=1; i<len; i++){
            if (nums[i] == num){
                continue;
            }else{
                int temp = nums[pivot];
                nums[pivot] = nums[i];
                nums[i] = temp;
                num = nums[pivot];
                pivot++;
            }
        }
        return pivot;
    }
};
