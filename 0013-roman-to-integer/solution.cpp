class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> ump;
        int num=0;
        ump['I']=1;
        ump['X']=10;
        ump['V']=5;
        ump['L']=50;
        ump['C']=100;
        ump['D']=500;
        ump['M']=1000;
        int i;
        
        for (i=0; i<s.size()-1; i++)
        {
            if (ump[s[i]] >= ump[s[i+1]])
            {
                num+=ump[s[i]];
            }
            else
            {
                num+=ump[s[i+1]]-ump[s[i]];
                i++;
            }
        }
        
        if (i==s.size()-1)
        {
            num+=ump[s[i]];
        }
        
        return num;
    }
};
