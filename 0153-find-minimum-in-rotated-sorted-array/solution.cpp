class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int res = -1;
        while (l<=r){
            int mid = l + (r-l)/2;
            cout<<"mid "<<mid<<" ";
            if (mid+1<n && mid-1>=0 && nums[mid+1]>nums[mid] && nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            else if(nums[mid]>=nums[l] && nums[mid]>nums[r]){
                l = mid+1;
            }else{  
                r = mid-1;
            }
        }
        return nums[l];
    }
};
