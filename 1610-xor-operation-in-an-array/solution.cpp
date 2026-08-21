class Solution {
public:
    int xorOperation(int n, int start) {
        int num = start;
        int ans = start;
        for (int i=1; i<n; i++){
            num+=2;
            ans = ans ^ (num);
        }
        return ans;
    }
};
