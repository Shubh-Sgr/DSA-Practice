class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        ans[0] = 0;
        int onesCount = 0;
        int leftContri = 0;
        for (int i=1; i<n; i++){
            onesCount += boxes[i-1]-'0';
            leftContri += onesCount;
            ans[i] += leftContri;
        }
        onesCount = 0;
        int rightContri = 0;
        for (int i=n-2; i>=0; i--){
            onesCount += boxes[i+1]-'0';
            rightContri += onesCount;
            ans[i] += rightContri;
        }
        return ans;
    }
};
