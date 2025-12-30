class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // int cookSize = s.size();
        // int childLen = g.size();

        // sort(g.begin(),g.end());
        // sort(s.begin(),s.end());

        // int num = 0;
        // int i = cookSize-1;
        // int j = childLen-1;

        // while (i>=0 && j>=0){
        //     if (s[i] >= g[j]){
        //         num++;
        //         i--;
        //         j--;
        //     }else{
        //         j--;
        //     }
        // }
        // return num;

        int childLen = g.size();
        int cookieSize = s.size();
        int num = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = childLen-1;
        int j = cookieSize - 1;

        while (i>=0 && j>=0){
            if (s[j]>=g[i]){
                num++;
                i--;
                j--;
            }else{
                i--;
            }
        }
        return num;
    }
};
