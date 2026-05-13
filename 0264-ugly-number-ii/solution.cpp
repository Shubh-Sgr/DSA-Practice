class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans;
        ans.push_back(1);
        int i=0,j=0,k=0;
        

        while (ans.size()<n){
            int next = min(ans[i]*2,min(ans[j]*3, ans[k]*5));
            if (next == ans[i]*2){
                i++;
            }
            if (next == ans[j]*3){
                j++;
            }
            if (next == ans[k]*5){
                k++;
            }
            ans.push_back(next);
        }
        return ans[n-1];
    }
};
