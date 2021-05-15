class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size()==0)
        {
            return 0;
        }
        int m=needle.size();
        int n=haystack.size();
        int lps[m];
        lps[0]=0;
        int i=1;
        int ptr_pref=0;
        while (i<m)
        {
            if (needle[ptr_pref]==needle[i])
            {
                lps[i]=ptr_pref+1;
                ptr_pref++;
                i++;
            }
            else
            {
                if (ptr_pref==0){
                    lps[i]=0;
                    i++;
                }
                else
                {
                    ptr_pref=lps[ptr_pref-1];
                }
            }
        }
        i=0;
        int j=0;
        while (i<n)
        {
            if (haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j==0)
                {
                    i++;
                }
                else
                {
                    j=lps[j-1];
                }
            }
            if (j==m)
            {
                return (i-j);
            }
        }
        return -1;
    }
};
