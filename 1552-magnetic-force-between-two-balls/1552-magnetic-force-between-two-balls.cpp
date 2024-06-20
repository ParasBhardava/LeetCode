class Solution {

private:
    bool solve(vector<int>& position, int dist, int m)
    {
        int curr = position[0];
        int ans = 1;
        
        for(int i = 1; i < position.size(); i++)
        {
            if(position[i] - curr >= dist)
            {
                curr = position[i];
                ans++;
                if(ans >= m)
                    return true;
            }
        }
        
        return false;
    }
    
public:
    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        sort(position.begin(), position.end());
        int start = 0, end = position[n-1];
        
        int ans = 0;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(solve(position, mid, m))
            {
                ans = mid;
                start = mid + 1;
            }
            
            else
                end = mid - 1;

        }
        
        return ans;
    }
};