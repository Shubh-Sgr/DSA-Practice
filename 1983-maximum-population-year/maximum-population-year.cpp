class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int,int> ump;
        int n = logs.size();
        int j=INT_MAX,k=INT_MIN;
        for (int i=0; i<n; i++){
            ump[logs[i][0]]+=1;
            ump[logs[i][1]]-=1;
            j = min(j,logs[i][0]);
            k = max(k,logs[i][1]);
        }
        int candidateYear = logs[0][0];
        int maxCount=0,count=0;
        while (j<=k){
            count+=ump[j];
            if (count>maxCount){
                candidateYear = j;
                maxCount = count;
            }
            j++;
        }
        return candidateYear;
    }
};