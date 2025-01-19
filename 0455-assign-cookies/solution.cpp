class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookSize = s.size();
        int childLen = g.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int num = 0;
        int i = cookSize-1;
        int j = childLen-1;

        while (i>=0 && j>=0){
            if (s[i] >= g[j]){
                num++;
                i--;
                j--;
            }else{
                j--;
            }
        }
        return num;
    }
};
