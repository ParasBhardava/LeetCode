class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<pair<int, int>>adjl[n];
        vector<int>distance(n, INT_MAX);
        
        for(auto &flight : flights)
            adjl[flight[0]].push_back({flight[1], flight[2]});
        
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src, 0}});
        distance[src] = 0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k)
                continue;
            
            for(auto &it : adjl[node])
            {
                int adjNode = it.first;
                int weight = it.second;
                if(cost + weight < distance[adjNode] && stops <= k)
                {
                    distance[adjNode] = cost + weight;
                    q.push({stops + 1, {adjNode, distance[adjNode]}});
                }
            }
        }
        
        if(distance[dst] == INT_MAX)
            return -1;

        return distance[dst];
    }
};