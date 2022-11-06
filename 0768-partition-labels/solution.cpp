class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> ump;
        int n = s.size();
        
        for (int i=0; i<n; i++){
            ump[s[i]] = i;
        }
        
        int i=0;
        int max=0;
        int point=0;
        vector<int> ans;
        while (i<n){
            if (max<ump[s[i]]){
                max=ump[s[i]];
            }
            if (max==ump[s[i]] && i==ump[s[i]]){
                ans.push_back(i+1-point);
                point=i+1;
                max=0;
            }
            i++;
        }
        if (max!=0){
            ans.push_back(i+1-point);
        }
        return ans;
    }
};
