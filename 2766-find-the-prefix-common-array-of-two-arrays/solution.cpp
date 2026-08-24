class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;

        long long maskA = 0;
        long long maskB = 0;

        for (int i = 0; i < n; i++) {
            maskA |= (1LL << A[i]);
            maskB |= (1LL << B[i]);

            ans.push_back(__builtin_popcountll(maskA & maskB));
        }

        return ans;
    }
};
