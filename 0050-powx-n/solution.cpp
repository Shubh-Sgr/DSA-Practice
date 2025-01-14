class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.00;
        long long m = n;
        m = m<0?(-1)*m:m;
        while (m != 0){
            if (m%2==0){
                x = x*x;
                m=m/2;
            }else{
                ans=ans*x;
                m--;
            }
        }
        return n<0 ? 1.00/ans : ans;
    }
};
