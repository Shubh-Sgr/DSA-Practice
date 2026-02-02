class Solution {
public:
    string digitToRoman(int digit, char ones, char second, char ths){
        if (digit<=3){
            return string(digit, ones);
        }else if (digit == 4){
            return string()+ones+second;
        }else if (digit<=8){
            return string()+second+string(digit-5,ones);
        }
        return string()+ ones+ths;
    }
    string intToRoman(int num) {
        string result = "";
        result+=string(num/1000,'M');
        num=num%1000;

        result += digitToRoman(num/100,'C','D','M');
        num = num%100;

        result += digitToRoman(num/10,'X','L','C');
        num = num%10;

        result += digitToRoman(num,'I','V','X');
        return result;
    }
};
