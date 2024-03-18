class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
     
        int n = points.size();
        sort(points.begin(), points.end(), [&](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        
        int limit = points[0][1], count = 1;
            
        for(int  i = 1; i < n; i++)
        {
            if(points[i][0] <=  limit)
                continue;
            
            else
            {
                count++;
                limit = points[i][1];
            }
        }
        
        return count;
    }
};