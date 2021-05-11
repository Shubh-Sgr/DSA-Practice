class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int cZ=0,cO=0,cT=0;
        for (int i=0; i<n; i++)
        {
            if (nums[i]==0)
            {
                cZ++;
            }
            else if (nums[i]==1)
            {
                cO++;
            }
            else
            {
                cT++;
            }
        }
        for (int i=0; i<n; i++)
        {
            if (cZ)
            {
                nums[i]=0;
                cZ--;
            }
            else if (cO)
            {
                nums[i]=1;
                cO--;
            }
            else
            {
                nums[i]=2;
            }
        }
    }
};
