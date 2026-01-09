class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        int i =0;
        string ans = "";
        while (i<size){
            string temp = "";
            while (s[i]!=' ' && i<size){
                temp = temp + s[i];
                i++;
            }

            ans = temp + ans;

            while (s[i]==' ' && i<size){
                i++;
            }
            if (ans.size()!=0 && i<size){
                ans = ' '+ans;
            }
        }
        return ans;
    }
};
