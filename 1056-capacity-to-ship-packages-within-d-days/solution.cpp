class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxele = 0;
        int sum = 0;
        int n = weights.size();
        int left = maxele;

        for (int i=0; i<n; i++){
            left = max(left,weights[i]);
            sum+=weights[i];
        }
        int right = sum;

        while (left<right){
            int wt = left + (right-left)/2;
            int dC = 1;
            int innerSum = 0;

            for (int i=0; i<n; i++){
                if (innerSum+weights[i]>wt){
                    dC++;
                    innerSum = 0;
                }
                innerSum += weights[i];
            }
            if (dC>days){
                left = wt+1;
            }else{
                right = wt;
            }
        }
        return left;
    }
};
