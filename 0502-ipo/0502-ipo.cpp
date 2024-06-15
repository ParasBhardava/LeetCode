class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();
        vector<pair<int, int>>arr;
        for(int i = 0; i < n; i++)
            arr.push_back({profits[i], capital[i]});
        
        sort(arr.begin(), arr.end(), [&](pair<int, int>&a, pair<int, int>&b){
            if(a.second == b.second)
                return a.first > b.first;

            return a.second < b.second;
        });

        priority_queue<int>pq;
        int j = 0;

        for(int i = 0; i < k; i++)
        {
            while(j < n && arr[j].second <= w)
            {
                pq.push(arr[j].first);
                j++;
            }

            if(!pq.empty())
            {
                w += pq.top();
                pq.pop();
            }
        }

        return w;
    }
};