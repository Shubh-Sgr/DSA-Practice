class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> ump;
        int i=0,j=0,start=0,min=INT_MAX;
        for (int k=0; k<t.size(); k++){
            ump[t[k]]++;
        }
        int count = ump.size();

        while (j<s.size()){
            if (ump.count(s[j])) {
                ump[s[j]]--;
                if (ump[s[j]] == 0) count--;
            }

            while (count == 0){
                if (j-i+1<min){
                    min=j-i+1;
                    start=i;
                }

                if (ump.count(s[i])){
                    ump[s[i]]++;
                    if (ump[s[i]]>0){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return min == INT_MAX ? "" : s.substr(start, min);
    }
};
