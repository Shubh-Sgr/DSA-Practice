class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int st = -1;
        int res = 0;
        int n = arr.size();
        bool up = false;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                // start of a new mountain
                if (!up) {
                    st = i - 1;
                    up = true;
                }
                else{
                    if (i > 1 && arr[i] > arr[i - 1] && arr[i - 1] < arr[i - 2]) {
                    st = i - 1;
                    up = true;
                    }
                }
            }
            else if (arr[i] < arr[i - 1]) {
                if (st != -1 && up) {
                    // valid descent after ascent
                    res = max(res, i - st + 1);
                }
            }
            else {
                // flat section resets everything
                st = -1;
                up = false;
            }

            // if a new ascent starts after descent
            
        }
        return res;
    }
};
