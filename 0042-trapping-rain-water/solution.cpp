class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = 0;
        int maxRight = 0;
        int n = height.size();
        int l = 0;
        int r = n-1;
        int amount = 0;

        while (l < r){
            if (height[l]<=height[r]){
                if (maxLeft < height[l]){
                    maxLeft = height[l];
                }else{
                    amount+=(maxLeft-height[l]);
                }
                l++;
            }else{
                if (maxRight < height[r]){
                    maxRight = height[r];
                }else{
                    amount+=(maxRight-height[r]);
                }
                r--;
            }
        }
        return amount;
    }
};
