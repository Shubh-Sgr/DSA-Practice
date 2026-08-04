class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness = 0;
        for (int i=num1; i<=num2; i++){
            string temp = to_string(i);
            int len = temp.size();
            for (int j=1; j<len-1; j++){
                if ((temp[j]-'0')>(temp[j-1] -'0') && (temp[j] -'0')>(temp[j+1] -'0')){
                    waviness++;
                }
                if ((temp[j]-'0')<(temp[j-1] -'0') && (temp[j] -'0')<(temp[j+1] -'0')){
                    waviness++;
                }
            }
        }
        return waviness;
    }
};
