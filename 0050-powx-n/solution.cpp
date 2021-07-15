class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long m=n;
        if (m<0)
        {
            m=(-1)*m;
        }
        while (m!=0)
        {
            if (m%2==1)
            {
                ans=ans*x;
                m--;
            }
            else{
                x=x*x;
                m=m/2;
            }
        }
        if (n<0)
        {
            return double(1)/ans;
        }
        else
        {
            return ans;
        }
    }
};
