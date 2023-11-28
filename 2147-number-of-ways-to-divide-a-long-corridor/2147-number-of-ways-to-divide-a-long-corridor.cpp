class Solution {
public:
    int numberOfWays(string corridor) {
        
        const long long MOD = (int)1e9 + 7;
        int n = corridor.size();
        vector<int>seats;
        
        for(int i = 0 ; i < n; i++)
        {
            if(corridor[i] == 'S')
                seats.push_back(i);
        }
        
        if(seats.size() == 0 || seats.size() % 2)
            return 0;
        
        int prev = seats[1];
        long long ans = 1;
        for(int i = 2; i < seats.size(); i+=2)
        {
            ans = ans * (seats[i] - prev);
            ans %= MOD;
            prev = seats[i+1];
        }
        
        return ans;
    }
};