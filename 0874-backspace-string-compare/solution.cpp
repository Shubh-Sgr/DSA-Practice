class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int count = 0;
        string s1 = "";
        string s2 = "";
        for (int i=s.size()-1; i>=0; i--){
            if (s[i]!='#' && count==0){
                s1+=s[i];
            }else if (s[i]=='#'){
                count++;
            }else if (s[i]!='#' && count!=0){
                count--;
            }
        }
        count=0;
        for (int i=t.size()-1; i>=0; i--){
            if (t[i]!='#' && count==0){
                s2+=t[i];
            }else if (t[i]=='#'){
                count++;
            }
            else if (t[i]!='#' && count!=0){
                count--;
            }
        }
        cout<<"sjdj"<<s1<<" "<<s2<<" ";
        return s1==s2;
    }
};
