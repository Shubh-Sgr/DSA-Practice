class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        
        int even=0,odd=0;
        for (int i=0; i<n; i++)
        {
            even++;
            if (arr[i]%2==1)
            {
                int temp=odd;
                odd=even;
                even=temp;
            }
            ans=(ans+odd)%1000000007;
        }
        return ans;
    }
};
