class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>count(101, 0);
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        for (int i = 0; i < n; i++)
            pq.push({meetings[0][0], i});
        
        for (auto &meeting : meetings) 
        {
            while (pq.top().first < meeting[0])
            {
                pq.push({meeting[0], pq.top().second});
                pq.pop();
            }
            
            long long start = pq.top().first;
            long long room = pq.top().second;
            pq.pop();
            pq.push({start + meeting[1] - meeting[0], room});
            count[room]++;
        }
        
        return max_element(count.begin(), count.end()) - count.begin();
    }
};