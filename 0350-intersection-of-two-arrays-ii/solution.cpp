class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ump;
        vector<int> ans;
        int i=0,j=0,n1=nums1.size(),n2 = nums2.size();
        for (int i=0; i<n1; i++){
            ump[nums1[i]]++;
        }
        for (int i=0; i<n2; i++){
            if (ump.find(nums2[i])!=ump.end() && ump[nums2[i]]!=0){
                ans.push_back(nums2[i]);
                ump[nums2[i]]--;
            }
        }
        return ans;
    }
};
