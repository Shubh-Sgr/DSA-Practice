class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start=0;
        int maxLen = 0;
        int n = fruits.size();
        unordered_map<int,int> fruitMap;

        for (int i=0; i<n; i++){
            fruitMap[fruits[i]]++;
            while (fruitMap.size()>2){
                fruitMap[fruits[start]]--;
                if (fruitMap[fruits[start]]==0){
                    fruitMap.erase(fruits[start]);
                }
                start++;
            }
            maxLen = max(maxLen,i-start+1);
        }
        return maxLen;
    }
};
