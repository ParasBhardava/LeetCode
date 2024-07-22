class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<pair<string, int>>arr;
        for(int i = 0; i < n; i++)
            arr.push_back({names[i], heights[i]});
        
        sort(arr.begin(), arr.end(), [&](pair<string, int>&a, pair<string, int>&b){
            return a.second > b.second;
        });
        
        vector<string>res;
        for(int i = 0; i< n; i++)
            res.push_back(arr[i].first);
        
        return res;
    }
};