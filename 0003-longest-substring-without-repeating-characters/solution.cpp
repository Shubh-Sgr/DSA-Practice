class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0)
        {
            return 0;
        }
        int st=0;
        int end=0;
        unordered_map<char,int> ump;
        ump[s[0]]=0;
        int max=1;
        for (int i=1; i<s.size(); i++)
        {
            if (ump.find(s[i])!=ump.end())
            {
                if (st<=ump[s[i]]){
                    st=ump[s[i]]+1;
                }
                
            }
            ump[s[i]]=i;
            end=i;
            if (max<end-st+1)
            {
                cout<<i<<" "<<st<<"ok";
                max=end-st+1;
            }
        }
        return max;
    }
};
