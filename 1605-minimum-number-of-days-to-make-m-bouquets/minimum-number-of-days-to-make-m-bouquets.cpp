class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
       int n =  bloomDay.size();
       if ((long long)m * k > n)
            return -1;
       int low = INT_MAX, high = INT_MIN;
       for (int i=0; i<n; i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
       }
       while (low<high){
         int day = low + (high-low)/2;
         int bouq = 0;
         int flower = 0;
         for (int i=0; i<n; i++){
            if (bloomDay[i]<=day){
                flower++;
            }else if (bloomDay[i]>day && flower!=0){
                flower = 0;
            }
            if (flower == k){
                bouq++;
                flower=0;
            }
            if (bouq >= m)
                break;
         }
         if (bouq>=m){
            high = day;
         }else{
            low = day+1;
         }
       }
       return low;
    }
};