class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0){
            return 0;
        }
        int minVal = prices[0];
        int ans=0;
        for (int i=1;i<n; i++){
            if (minVal>prices[i]){
                minVal=prices[i];
            }
            else{
                ans = max(ans,prices[i]-minVal);
            }
        }
        return ans;
    }
};
