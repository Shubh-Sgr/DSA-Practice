class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int resultXor = 0;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++){
            resultXor = resultXor ^ nums[i];
        }
        int j=0;
        for (j=0; j<32; j++){
            if ((resultXor >> j) & 1){
                break;
            }
        }
        int firstNum = 0,secondNum = 0;
        for (int i=0; i<nums.size(); i++){
            if ((nums[i]>>j) & 1){
                firstNum = firstNum ^ nums[i];
            }else{
                secondNum = secondNum ^ nums[i];
            }
        }
        ans.push_back(firstNum);
        ans.push_back(secondNum);
        return ans;
    }
};
