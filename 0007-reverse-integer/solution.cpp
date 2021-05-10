class Solution {
public:
    int reverse(int x) {
        int rev=0;
        int rem;
        while (x)
        {
            rem=x%10;
            if (rev>2147483648/10 || rev<-2147483648/10)
            {
                return 0;
            }
            rev=rev*10+rem;
            // cout<<rev<<" ";
            
            x=x/10;
        }
        if (x<0)
        {
            rev=-rev;
        }
        return rev;
    }
};
