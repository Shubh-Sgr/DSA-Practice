class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        if (n==0){
            return 0;
        }
        long long currCount = 1;
        long long ans = 1;
        for (int i=1; i<n; i++){
            if (prices[i]<prices[i-1] && prices[i-1]-prices[i]==1){
                currCount++;
            }else{
                currCount=1;
            }
            ans+=currCount;
        }
        return ans;
    }
};
