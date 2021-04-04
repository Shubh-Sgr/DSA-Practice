class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int f=0;
        int pos=0;
        unsigned int ans=0;
        for (int i=31; i>=0; i--)
        {
            if (!f)
            {
                if ((1<<i) & (n))
                {
                    f=1;
                    // cout<<i<<" ";
                    
                }
            }
            if (f)
            {
                if ((1<<i) & (n)){
                unsigned int sm=1;
                sm=sm<<(pos);
                ans=ans|sm;
                }
            }
             pos++;
        }
        // cout<<pos<<" ";
        return ans;
    }
};
