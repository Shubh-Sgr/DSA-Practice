class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>> p;
        for (int i=0; i<points.size(); i++){
            int x=points[i][0];
            int y=points[i][1];
            p.push({x*x+y*y,x,y});
            if (p.size()>k){
                p.pop();
            }
        }
        for (int i=0; i<k; i++){
            vector<int> temp;
            temp.push_back((p.top())[1]);
            temp.push_back((p.top())[2]);
            p.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};
