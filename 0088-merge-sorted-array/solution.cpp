class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int fullSize = m+n;
        if (m==0){
            for (int i = 0; i < n; i++){
                nums1[i] = nums2[i]; 
            }
        }
        int curr = m+n-1;
        int fr = m-1;
        int sr = n-1;

        while (fr >= 0 && sr >= 0){
            if (nums1[fr]> nums2[sr]){
                nums1[curr] = nums1[fr];
                fr--;
            }else{
                nums1[curr] = nums2[sr];
                sr--;
            }
            curr--;
        }
        if (sr >=0 ){
            for (int i = sr; i>=0; i--){
                nums1[curr] = nums2[sr];
                curr--;
                sr--;
            }
        } 
    }
};
