class Graph {

private:
    vector<vector<pair<int, int>>> adjl;
    
public:
    Graph(int n, vector<vector<int>>& edges) {
        
        adjl.resize(n);
        for (auto& edge : edges)
            adjl[edge[0]].push_back({edge[1], edge[2]});
    }
    
    void addEdge(vector<int> edge) {
        adjl[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int n = adjl.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n, INT_MAX);

        distance[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(node == node2)
                return dist;

            for (auto it : adjl[node])
            {
                int next = it.first;
                int nextDist = it.second;

                if (nextDist + dist < distance[next])
                {
                    distance[next] = nextDist + dist;
                    pq.push({distance[next], next});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */