class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char, int> ump;
        for (int j=0; j<n; j++){
            ump[s[j]] = j;
        }
        int i = 0;
        int maxJump;
        int st;
        while (i<n){
            st = i;
            maxJump = ump[s[i]];
            while (i<maxJump && i<n){
                i++;
                maxJump = ump[s[i]]>maxJump ? ump[s[i]]: maxJump;
            }
            ans.push_back(i-st+1);
            i++;
        }
        return ans;
    }
};
