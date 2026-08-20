class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n==0){
            return true;
        }
        int prev = n & 1;
        n = n >> 1;

        while (n) {
            int temp = n & 1;

            if (temp == prev) {
                return false;
            }

            prev = temp;
            n = n >> 1;
        }

        return true;
    }
};
