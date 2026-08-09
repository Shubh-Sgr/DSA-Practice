class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        int n = people.size();
        sort(people.begin(),people.end());
        int l = 0,r=n-1;
        while(l<=r){
            if (people[l]+people[r]<=limit){
                boats++;
                l++;
                r--;
            }else{
                r--;
                boats++;
            }
        }
        return boats;
    }
};
