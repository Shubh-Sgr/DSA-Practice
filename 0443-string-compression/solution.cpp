class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i=0;

        while (i<n){
            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i]==ch){
                count++;
                i++;
            }

            chars[index] = ch;
            index++;

            if (count>1){
                string  cnt = to_string(count);
                for (int j=0; j<cnt.size(); j++){
                    chars[index] = cnt[j];
                    index++;
                }
            }
        }
        return index;
    }
};
