class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target)
            return 0;
        
        int n = routes.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j<routes[i].size(); j++)
            {
                int currStop = routes[i][j];
                int currBus = i;
                mp[currStop].push_back(currBus); 
            }
        }
     
        int level = 0;
        vector<int>visitedBus(n, false);
        unordered_map<int, bool>visitedStops;
        
        queue<pair<int, int>>q;
        q.push({source, 0});
        visitedStops[source] = true;
        
        while(!q.empty())
        {
            int currStop = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(currStop == target)
                return level;
            
            vector<int>busOption = mp[currStop];
            for(int i = 0; i < busOption.size(); i++)
            {
                int currBus = busOption[i];
                if(visitedBus[currBus])
                    continue;
                
                else
                {
                    vector<int> nextStops = routes[currBus];
                    for(int j = 0; j < nextStops.size(); j++)
                    {
                        int nextStop = nextStops[j];
                        if(visitedStops[nextStop]) 
                            continue;
                        
                        else
                        {
                            q.push({nextStop, level + 1});
                            visitedStops[nextStop] = true;
                        }
                    }
                    visitedBus[currBus] = true;
                }
                    
            }
        }
        
        return -1;
    }
};