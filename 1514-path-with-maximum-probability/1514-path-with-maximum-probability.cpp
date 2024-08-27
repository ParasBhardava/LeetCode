class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int, double>> adjl[n];
        for(int i = 0; i < edges.size(); i++)
        {
            adjl[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjl[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
            
        vector<double>probability(n, 0);
        probability[start] = 1;
        
        priority_queue<pair<double, int>>pq;
        pq.push({1, start});
        
        while(!pq.empty())
        {
            int node =  pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            
            for(auto &i: adjl[node])
            {
                int next = i.first;
                double nextProb = i.second;
                // cout<<node<<" "<<prob<<" "<<next<<" "<<nextProb<<"\n";
               
                if(prob * nextProb > probability[next])
                {
                    pq.push({prob * nextProb, next});
                    probability[next] = prob * nextProb; 
                }
            }
            
        }
        
        return probability[end];
        
    }
};