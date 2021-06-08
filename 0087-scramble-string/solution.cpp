class Solution {
public:
    unordered_map<string,bool> ump;
    bool isScrambleUtil(string s1,string s2){
        int i=s1.size();
        if (i==0){
            return true;
        }
        if (i==1 && s1[i-1]==s2[i-1]){
            return true;
        }
        if (i==1 && s1[i-1]!=s2[i-1]){
            return false;
        }
        string temp=s1+" "+s2;
        if (ump.find(temp)!=ump.end()){
            return ump[temp];
        }
        int ans=false;
        int n=s1.size();
        for (int k=1; k<n; k++){
            ans=ans || (isScrambleUtil(s1.substr(0,k),s2.substr(n-k,k)) && isScrambleUtil(s1.substr(k),s2.substr(0,n-k)));
            ans=ans || (isScrambleUtil(s1.substr(0,k),s2.substr(0,k)) && isScrambleUtil(s1.substr(k),s2.substr(k)));
        }
        return ump[temp]=ans;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size()-1;
        return isScrambleUtil(s1,s2);
    }
};
