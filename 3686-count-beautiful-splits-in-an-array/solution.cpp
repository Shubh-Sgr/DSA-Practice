class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (nums[i] == nums[j])
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
            }
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int len1 = i;
                int len2 = j - i;
                int len3 = n - j;

                bool ok = false;

                if (len1 <= len2 && lcp[0][i] >= len1)
                    ok = true;

                if (len2 <= len3 && lcp[i][j] >= len2)
                    ok = true;

                if (ok)
                    ans++;
            }
        }

        return ans;
    }
};
