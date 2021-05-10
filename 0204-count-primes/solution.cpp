class Solution {
public:
    int countPrimes(int n) {
        int m=n;
        int arr[5000000];
        for (int i=0; i<n; i++)
        {
            arr[i]=0;
        }
        if (n<2)
        {
            return 0;
        }
        arr[2]=0;
        for (int i=2; i<n; i++)
        {
            if (arr[i]==0)
            {
                for (int j=2; j*i<n; j++)
                {
                    arr[j*i]=1;
                }
            }
        }
        int c=0;
        for (int i=2; i<n; i++)
        {
            if (arr[i]==0)
            {
                c++;
            }
        }
        return c;

    }
};
