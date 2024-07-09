class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n = customers.size();
        int availableAt = 0;
        long long totalWaitingTime = 0LL;
        
        for (auto& customer : customers) 
        {
            int arrival = customer[0];
            int time = customer[1];
            availableAt = max(availableAt, arrival) + time;
            totalWaitingTime += availableAt - arrival;
        }
        return (1.0 * totalWaitingTime) / n;
    }
};