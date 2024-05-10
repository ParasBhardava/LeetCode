class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n = arr.size();
        priority_queue<pair<double, pair<int,int>>>pq;
        for(int i = 0; i < n; i++)
            pq.push({-1.0 * arr[i]/arr.back(), {i, n - 1}});
        
        while(--k > 0)
        {
            pair<int,int> curr = pq.top().second;
            pq.pop();
            curr.second--;
            pq.push({-1.0*arr[curr.first]/arr[curr.second], {curr.first, curr.second}});
        }
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};