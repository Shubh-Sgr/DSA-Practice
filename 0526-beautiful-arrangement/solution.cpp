class Solution {
public:
    int count=0;
    
    
    void Utils(int nums[],int end)
    {
        if (end==0)
        {
            count++;
            return;
        }
        
        for (int i=end; i>0; i--)
        {
            int temp=nums[end];
            nums[end]=nums[i];
            nums[i]=temp;
            
            if (nums[end]%end==0 || end%nums[end]==0)
            {
                Utils(nums,end-1);
            }
            
            temp=nums[end];
            nums[end]=nums[i];
            nums[i]=temp;
        }
    }
    
    int countArrangement(int n) {
        int *nums = new int[n+1];
        for (int i=0; i<=n; i++)
        {
            nums[i]=i;
        }
        Utils(nums,n);
        return count;
    }
};
