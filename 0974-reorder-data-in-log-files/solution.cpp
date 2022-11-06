class Solution {
public:
    static bool compare(pair<string,string> p1,pair<string,string> p2){
        return p1.second==p2.second?p1.first<p2.first:p1.second<p2.second;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        vector<string> digits;
        vector<pair<string,string>> letters;
        for (string &str: logs){
            int j=0;
            int d=0;
            while (str[j]!= ' '){
                j++;
            }
            if (isalpha(str[j + 1])){
                letters.emplace_back(str.substr(0,j),str.substr(j + 1));
            }
            else{
                digits.push_back(str);
            }
        }
        sort(letters.begin(),letters.end(),compare);
        for (int i=0; i<letters.size(); i++){
            ans.push_back(letters[i].first+" "+letters[i].second);
        }
        for (int i=0; i<digits.size(); i++){
            ans.push_back(digits[i]);
        }
        return ans;
    }
};
