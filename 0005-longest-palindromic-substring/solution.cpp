class Solution {
public:
    string pallindrom(string s, int i ,int j){
        int n = s.size();
        string ans = "";
        while (i>=0 && j<n){
            if (s[i]==s[j]){
                i--;
                j++;
            }else{
                break;
            }
        }

        if (i<0){
            i=-1;
        }
        if (j>=n){
            j=n;
        }

        for (int k = i+1; k<j; k++){
            ans+=s[k];
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int maxCount = 0;
        string ans = "";
        int n = s.size();
        if (s.size()<=1){
            return s;
        }
        for (int i=0; i<n-1; i++){
            string p1 = pallindrom(s,i,i);
            string p2 = pallindrom(s,i,i+1);
            if (p1.size()>maxCount && p1.size()>p2.size()){
                maxCount = p1.size();
                ans = p1;
            }else if(p2.size()>maxCount && p2.size()>p1.size()){
                maxCount = p2.size();
                ans = p2;
            }
        }
        return ans;
    }
};
