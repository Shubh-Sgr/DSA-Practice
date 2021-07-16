class Solution {
public:
    void merge(vector<int> &nums,int st,int mid,int end)
    {
        int n=end-st+1;
        int b[n];
        int i=st,j=mid+1,k=0;
        while (i<=mid && j<=end)
        {
            if (nums[i]>nums[j])
            {
                
                b[k++]=nums[j++];
                
            }
            else
            {
                b[k++]=nums[i++];
            }
        }
        while (i<=mid)
        {
            b[k++]= nums[i++];
        }
        while (j<=end)
        {
            b[k++]= nums[j++];
        }
        k=0;
        for (int i=st; i<=end; i++)
        {
            nums[i]=b[k++];
        }
    }
    void mergesort(vector<int> &nums,int st,int end,int &count)
    {
        if (st<end)
        {
            int mid=(st+end)/2;
            mergesort(nums,st,mid,count);
            mergesort(nums,mid+1,end,count);
            int j=mid+1;
            for (int i=st; i<=mid; i++)
            {
                while (j<=end && nums[i]>2*long(nums[j]))
                {
                    j++;
                }
                count+=(j-(mid+1));
            }
                // if (count==1)
                //   cout<<j<<" ";
            cout<<endl;
            merge(nums,st,mid,end);
        }
    }
    
    int reversePairs(vector<int>& nums) {
        int count=0;
        mergesort(nums,0,nums.size()-1,count);
        return count;
    }
};
