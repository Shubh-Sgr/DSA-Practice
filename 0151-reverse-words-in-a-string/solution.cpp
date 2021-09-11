class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0;
        while (i<s.size())
        {
            string temp;
            while (s[i]!=' ' && i<s.size())
            {
                temp+=s[i];
                 i++;
            }
            ans=temp+ans;
            
            while (s[i]==' ' && i<s.size())
            {
                 i++;
            }
            
            if (i<s.size() && ans.size()!=0)
            {
                ans=" "+ans;
            }
        }
    return ans;
    }
};
