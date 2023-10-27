class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainders(60);
        int ans = 0;
        int len = time.size();

        for (int i=0; i<len; i++){
          if (time[i]%60==0){
            ans+=remainders[0];
          }
          else{
            ans+=remainders[60-time[i]%60];
          }
          remainders[time[i]%60]++;
        }
        return ans;
    }
};
