class Solution {
public:
    bool isUgly(int n) {
        int arr[] = {2,3,5};
        int i=2;
        if (n==0){
            return false;
        }
        while (i>=0){
            if(n==1){
                return true;
            }
            if (n%arr[i]==0){
                n = n/arr[i];
            }else{
                i--;
            }
        }
        return false;
    }
};
