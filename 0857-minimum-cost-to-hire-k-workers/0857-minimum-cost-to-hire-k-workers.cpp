class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>>arr;
        for(int i = 0; i < n; i++)
            arr.push_back({wage[i] * 1.0 / quality[i], quality[i]}); 
        
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.first < b.first;
        });
        
        int qualityCount = 0;
        priority_queue<int> pq;
        for(int i = 0; i < k; i++)
        {
            qualityCount += arr[i].second;
            pq.push(arr[i].second);
        }
        
        double ans = qualityCount * arr[k - 1].first;
        for(int i = k; i < n; i++) 
        {
            pq.push(arr[i].second);
            qualityCount += arr[i].second;
            qualityCount -= pq.top();
            pq.pop();
            ans = min(ans, qualityCount * arr[i].first);
        }
        return ans;
    }
};