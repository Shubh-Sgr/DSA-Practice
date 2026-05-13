class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0){
            return 1;
        }else if(n==1){
            return 10;
        }
        int prev = 10;
        int curr;
        for (int i=2; i<=n; i++){
            int res = 9;
            int ans = 9;
            for (int j = 2; j<=i; j++){
                ans = ans*(res);
                res-=1;
            }
            curr = prev+ans;
            prev = curr;
        }
        return curr;
    }
};
